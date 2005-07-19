#!/bin/sh
# start sendmail X via MCP

MCPPID=mcp.pid
MCPOUT=mcp.out

start_mcp()
{
	${sbindir}/mcp -l -p \${MCPPID} ${SMXCNF} > \${MCPOUT} 2>&1 &
}

stop_mcp()
{
	if test -s \${MCPPID}; then
		kill \`head -1 \${MCPPID}\`
	else
		echo "\$0: pid file \${MCPPID} does not exist or is empty"
	fi
}

if cd "${SMXQD}"; then
	:
else
	echo "\$0: cd ${SMXQD} failed"
	exit 1
fi

case "\$1" in
'start')
	start_mcp
	;;
'stop')
	stop_mcp
	;;
'restart')
	stop_mcp
	start_mcp
	;;
*)
	echo "Usage: \$0 { start | stop | restart }"
	exit 1
	;;
esac
exit 0
