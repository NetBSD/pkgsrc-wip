#!/bin/sh
#
# $NetBSD: tkabber.sh,v 1.1.1.1 2003/11/28 18:02:03 xtraeme Exp $

exec @PREFIX@/bin/wish @DATADIR@/tkabber.tcl -name tkabber "$$@"
