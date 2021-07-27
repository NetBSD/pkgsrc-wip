#!/bin/sh -e

sed -i'' -e 's|^man/man3/BL_|${PLIST.cs}&|' PLIST.new
