#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: taskchampion-sync-server
#
# PROVIDE: taskchampion-sync-server
# REQUIRES: network
# KEYWORD: shutdown
# 
# Per docs generate a client id using `uuidgen` and change the port if required
#
# - https://gothenburgbitfactory.org/taskchampion-sync-server/usage/binaries.html
# - https://taskwarrior.org/docs/man/task-sync.5/

$_rc_subr_loaded . /etc/rc.subr

name="taskchampion_sync_server"
rcvar=$name
command="/usr/pkg/bin/taskchampion-sync-server"
taskchampion_sync_server_port=19080
taskchampion_sync_server_client_id=111a11aa-1111-1111-111a-aaa1a1a1a1a1
taskchampion_sync_server_log="/var/log/taskchampion_sync_server.log"
taskchampion_sync_server_env="RUST_LOG=info"
taskchampion_sync_server_flags="--listen localhost:$taskchampion_sync_server_port --allow-client-id $taskchampion_sync_server_client_id >> $taskchampion_sync_server_log 2>&1 &"

load_rc_config $name
run_rc_command "$1"
