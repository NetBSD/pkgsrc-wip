#!/bin/sh

# nncp-caller itself doesn't daemonize when run non-interactively
( cd /; @PREFIX@/bin/nncp-caller < /dev/null >/dev/null 2>&1 & echo $! > @VARBASE@/run/nncp-caller.pid ) &
