// -*- mode:C++; tab-width:8; c-basic-offset:2; indent-tabs-mode:t -*-
// vim: ts=8 sw=2 smarttab
/*
 * Ceph - scalable distributed file system
 *
 * Copyright (C) 2013 Cloudwatt <libre.licensing@cloudwatt.com>
 *
 * Author: Loic Dachary <loic@dachary.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Library Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library Public License for more details.
 *
 */

#include <stdio.h>
#include <signal.h>
#include "mon/Monitor.h"
#include "common/ceph_argparse.h"
#include "global/global_init.h"
#include "common/debug.h"
#include <gtest/gtest.h>
// MUST be after gtest otherwise dout() won't compile with a strange message
#include "include/assert.h"

#define dout_subsys ceph_subsys_mon

#undef COMMAND
static MonCommand mon_commands[] = {
#define COMMAND(parsesig, helptext, modulename, req_perms, avail) \
  {parsesig, helptext, modulename, req_perms, avail},
#include <mon/MonCommands.h>
};

TEST(get_command_descriptions, builtin) {
  bufferlist rdata;
  get_command_descriptions(mon_commands, ARRAY_SIZE(mon_commands), &rdata);
  string data(rdata.c_str());
  dout(10) << data << dendl;
  EXPECT_NE(string::npos, data.find("cmd000"));
}

// syntax error https://github.com/ceph/ceph/pull/585
TEST(get_command_descriptions, pull585) {
  MonCommand mon_commands[] = {
    { "osd pool create "		       
      "name=pool,type=CephPoolname " 
      "name=pg_num,type=CephInt,range=0 " 
      "name=pgp_num,type=CephInt,range=0,req=false" // !!! missing trailing space
      "name=properties,type=CephString,n=N,req=false,goodchars=[A-Za-z0-9-_.=]", 
      "create pool", "osd", "rw", "cli,rest" }
  };
  bufferlist rdata;
  get_command_descriptions(mon_commands, ARRAY_SIZE(mon_commands), &rdata);
  string data(rdata.c_str());
  dout(10) << data << dendl;
  EXPECT_NE(string::npos, data.find("falsename"));
}

int main(int argc, char **argv) {
  vector<const char*> args;
  argv_to_vec(argc, (const char **)argv, args);

  global_init(NULL, args, CEPH_ENTITY_TYPE_CLIENT, CODE_ENVIRONMENT_UTILITY, 0);
  common_init_finish(g_ceph_context);

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// Local Variables:
// compile-command: "cd ../.. ; make unittest_get_command_descriptions && ./unittest_get_command_descriptions --gtest_filter=*.* --log-to-stderr=true --debug-mon=20"
// End:
