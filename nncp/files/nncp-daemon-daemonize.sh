#!/bin/sh

# nncp-daemon itself doesn't daemonize when run non-interactively
( cd /; @PREFIX@/bin/nncp-daemon < /dev/null >/dev/null 2>&1 & echo $! > @VARBASE@/run/nncp-daemon.pid ) &
