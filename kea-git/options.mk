# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.kea
PKG_SUPPORTED_OPTIONS=		mysql pgsql tests
PKG_SUGGESTED_OPTIONS=		mysql pgsql
PLIST_VARS+=			mysql pgsql

.include "../../mk/bsd.options.mk"

###
### database support
###

.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=--with-mysql=${PREFIX}/bin/mysql_config
PLIST.mysql=yes
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_8.2_to_9.0.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_3.0_to_4.0.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_4.0_to_4.1.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/wipe_data.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_8.1_to_8.2.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_5.2_to_6.0.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_8.0_to_8.1.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_2.0_to_3.0.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_4.1_to_5.0.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_1.0_to_2.0.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_5.0_to_5.1.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_7.0_to_8.0.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_5.1_to_5.2.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_6.0_to_7.0.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_9.0_to_9.1.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_9.1_to_9.2.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_9.2_to_9.3.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_9.3_to_9.4.sh.in
REPLACE_BASH+= src/share/database/scripts/mysql/upgrade_9.4_to_9.5.sh.in
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=--with-pgsql=${PGSQL_PREFIX}/bin/pg_config
PLIST.pgsql=yes
REPLACE_BASH+= src/share/database/scripts/pgsql/upgrade_3.0_to_3.1.sh.in
REPLACE_BASH+= src/share/database/scripts/pgsql/upgrade_1.0_to_2.0.sh.in
REPLACE_BASH+= src/share/database/scripts/pgsql/upgrade_5.0_to_5.1.sh.in
REPLACE_BASH+= src/share/database/scripts/pgsql/wipe_data.sh.in
REPLACE_BASH+= src/share/database/scripts/pgsql/upgrade_3.2_to_3.3.sh.in
REPLACE_BASH+= src/share/database/scripts/pgsql/upgrade_3.1_to_3.2.sh.in
REPLACE_BASH+= src/share/database/scripts/pgsql/upgrade_3.3_to_4.0.sh.in
REPLACE_BASH+= src/share/database/scripts/pgsql/upgrade_5.1_to_6.0.sh.in
REPLACE_BASH+= src/share/database/scripts/pgsql/upgrade_2.0_to_3.0.sh.in
REPLACE_BASH+= src/share/database/scripts/pgsql/upgrade_4.0_to_5.0.sh.in
REPLACE_BASH+= src/share/database/scripts/pgsql/upgrade_6.0_to_6.1.sh.in
REPLACE_BASH+= src/share/database/scripts/pgsql/upgrade_6.1_to_6.2.sh.in
.endif

.if !empty(PKG_OPTIONS:Mtests)
.  include "../../devel/googletest/buildlink3.mk"
CONFIGURE_ARGS+=--with-gtest=${BUILDLINK_PREFIX.googletest}
REPLACE_BASH+= src/bin/dhcp6/tests/dhcp6_process_tests.sh.in
REPLACE_BASH+= src/bin/admin/tests/memfile_tests.sh.in
REPLACE_BASH+= src/bin/admin/tests/pgsql_tests.sh.in
REPLACE_BASH+= src/bin/admin/tests/mysql_tests.sh.in
REPLACE_BASH+= src/bin/admin/tests/cql_tests.sh.in
REPLACE_BASH+= src/bin/agent/tests/ca_process_tests.sh.in
REPLACE_BASH+= src/bin/keactrl/tests/keactrl_tests.sh.in
REPLACE_BASH+= src/bin/d2/tests/d2_process_tests.sh.in
REPLACE_BASH+= src/bin/shell/tests/shell_process_tests.sh.in
REPLACE_BASH+= src/bin/netconf/tests/shtests/netconf_tests.sh.in
REPLACE_BASH+= src/bin/dhcp4/tests/dhcp4_process_tests.sh.in
REPLACE_BASH+= src/lib/util/tests/process_spawn_app.sh.in
REPLACE_BASH+= src/lib/testutils/dhcp_test_lib.sh.in
REPLACE_BASH+= src/lib/log/tests/local_file_test.sh.in
REPLACE_BASH+= src/lib/log/tests/buffer_logger_test.sh.in
REPLACE_BASH+= src/lib/log/tests/init_logger_test.sh.in
REPLACE_BASH+= src/lib/log/tests/severity_test.sh.in
REPLACE_BASH+= src/lib/log/tests/destination_test.sh.in
REPLACE_BASH+= src/lib/log/tests/logger_lock_test.sh.in
REPLACE_BASH+= src/lib/log/tests/console_test.sh.in
.endif
