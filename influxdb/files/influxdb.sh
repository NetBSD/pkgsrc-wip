#!@RCD_SCRIPTS_SHELL@

# PROVIDE: influxdb
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
        . /etc/rc.subr
fi

name="influxdb"
rcvar=$name
influxdb_user="@INFLUXDB_USER@"
influxdb_group="@INFLUXDB_GROUP@"
influxdb_chdir="@VARBASE@/lib/influxdb"
pidfile="@VARBASE@/lib/influxdb/data/influxdb.pid"
STDOUT="@LOGDIR@/influxdb.log"
command="@PREFIX@/sbin/influxd"
command_args=">> $STDOUT &"

load_rc_config $name
run_rc_command "$1"
