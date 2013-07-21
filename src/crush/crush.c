
#ifdef __KERNEL__
# include <linux/slab.h>
#else
# include <stdlib.h>
# include <assert.h>
# define kfree(x) do { if (x) free(x); } while (0)
# define BUG_ON(x) assert(!(x))
# include "include/inttypes.h"
#endif

#include "crush.h"

const char *crush_bucket_alg_name(int alg)
{
	switch (alg) {
	case CRUSH_BUCKET_UNIFORM: return "uniform";
	case CRUSH_BUCKET_LIST: return "list";
	case CRUSH_BUCKET_TREE: return "tree";
	case CRUSH_BUCKET_STRAW: return "straw";
	default: return "unknown";
	}
}

/**
 * crush_get_bucket_item_weight - Get weight of an item in given bucket
 * @param b bucket pointer
 * @param p item index in bucket
 */
int crush_get_bucket_item_weight(const struct crush_bucket *b, int p)
{
	if ((__u32)p >= b->size)
		return 0;

	switch (b->alg) {
	case CRUSH_BUCKET_UNIFORM:
		return ((struct crush_bucket_uniform *)b)->item_weight;
	case CRUSH_BUCKET_LIST:
		return ((struct crush_bucket_list *)b)->item_weights[p];
	case CRUSH_BUCKET_TREE:
		return ((struct crush_bucket_tree *)b)->node_weights[crush_calc_tree_node(p)];
	case CRUSH_BUCKET_STRAW:
		return ((struct crush_bucket_straw *)b)->item_weights[p];
	}
	return 0;
}

void crush_destroy_bucket_uniform(struct crush_bucket_uniform *b)
{
	kfree(b->h.perm);
	kfree(b->h.items);
	kfree(b);
}

void crush_destroy_bucket_list(struct crush_bucket_list *b)
{
	kfree(b->item_weights);
	kfree(b->sum_weights);
	kfree(b->h.perm);
	kfree(b->h.items);
	kfree(b);
}

void crush_destroy_bucket_tree(struct crush_bucket_tree *b)
{
	kfree(b->h.perm);
	kfree(b->h.items);
	kfree(b->node_weights);
	kfree(b);
}

void crush_destroy_bucket_straw(struct crush_bucket_straw *b)
{
	kfree(b->straws);
	kfree(b->item_weights);
	kfree(b->h.perm);
	kfree(b->h.items);
	kfree(b);
}

void crush_destroy_bucket(struct crush_bucket *b)
{
	switch (b->alg) {
	case CRUSH_BUCKET_UNIFORM:
		crush_destroy_bucket_uniform((struct crush_bucket_uniform *)b);
		break;
	case CRUSH_BUCKET_LIST:
		crush_destroy_bucket_list((struct crush_bucket_list *)b);
		break;
	case CRUSH_BUCKET_TREE:
		crush_destroy_bucket_tree((struct crush_bucket_tree *)b);
		break;
	case CRUSH_BUCKET_STRAW:
		crush_destroy_bucket_straw((struct crush_bucket_straw *)b);
		break;
	}
}

/**
 * crush_destroy - Destroy a crush_map
 * @param map crush_map pointer
 */
void crush_destroy(struct crush_map *map)
{
	/* buckets */
	if (map->buckets) {
		__s32 b;
		for (b = 0; b < map->max_buckets; b++) {
			if (map->buckets[b] == NULL)
				continue;
			crush_destroy_bucket(map->buckets[b]);
		}
		kfree(map->buckets);
	}

	/* rules */
	if (map->rules) {
		__u32 b;
		for (b = 0; b < map->max_rules; b++)
			crush_destroy_rule(map->rules[b]);
		kfree(map->rules);
	}

	kfree(map->choose_tries);
	kfree(map);
}

void crush_destroy_rule(struct crush_rule *rule)
{
	kfree(rule);
}

// methods to check for safe arithmetic operations
int crush_addition_is_unsafe(__u32 a, __u32 b)
{
  if ((((__u32)(-1)) - b) < a)
    return 1;
  else
    return 0;
}

int crush_multiplication_is_unsafe(__u32  a, __u32 b)
{
  if ((((__u32)(-1)) / b) < a)
    return 1;
  else
    return 0;
}
