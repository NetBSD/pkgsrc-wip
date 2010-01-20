# $NetBSD: dist.mk,v 1.4 2010/01/20 07:53:21 tnn2 Exp $
#
# used by wip/xulrunner/Makefile
# used by wip/firefox/Makefile

DISTNAME=	firefox-${FIREFOX_VER}.source
FIREFOX_VER=	3.6rc2
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

DISTINFO_FILE=	${.CURDIR}/../../wip/xulrunner/distinfo
PATCHDIR=	${.CURDIR}/../../wip/xulrunner/patches

WRKSRC=		${WRKDIR}/mozilla-1.9.2
