# $NetBSD: dist.mk,v 1.32 2013/05/12 01:49:16 makoto Exp $
#
# used by devel/xulrunner/Makefile
# used by www/firefox/Makefile

DISTNAME=	xulrunner-${FIREFOX_VER}.source
FIREFOX_VER=	${MOZ_BRANCH}${MOZ_BRANCH_MINOR}
MOZ_BRANCH=	21.0
MOZ_BRANCH_MINOR=
#MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/} \
#		${MASTER_SITE_MOZILLA_ALL:=firefox/releases/${FIREFOX_VER}/source/}
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/xulrunner/releases/${FIREFOX_VER}/source/
EXTRACT_SUFX=	.tar.bz2

DISTINFO_FILE=	${.CURDIR}/../../wip/xulrunner/distinfo
PATCHDIR=	${.CURDIR}/../../wip/xulrunner/patches

WRKSRC=		${WRKDIR}/mozilla-release
