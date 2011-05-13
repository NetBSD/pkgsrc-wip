# $NetBSD: hacks.mk,v 1.3 2011/05/13 23:25:15 mwdavies Exp $

#
# Can't figure out why the kruler build is prefering the below file
# rather than the one generated in _KDE_build/kruler so for the
# time being just get rid of it.
#

post-configure:
	rm ${BUILDLINK_DIR}/include/kruler.h
