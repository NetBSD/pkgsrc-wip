#!/bin/sh -e

# pkg-remake plugin for local changes to PLIST folling make print-PLIST
sed -i'' -e 's|^man/man3/STATSF.*_SET_|${PLIST.cs}&|' PLIST.new
