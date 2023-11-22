#!/bin/sh

# nncp-toss itself doesn't daemonize when run non-interactively
( cd /; @PREFIX@/bin/nncp-toss < /dev/null >/dev/null 2>&1 & echo $! > @VARBASE@/run/nncp-toss.pid ) &
