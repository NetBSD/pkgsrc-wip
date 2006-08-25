#!/bin/sh
#
# $NetBSD: tkabber.sh,v 1.2 2006/08/25 11:21:32 minskim Exp $

exec @WISH@ @DATADIR@/tkabber.tcl -name tkabber "$$@"
