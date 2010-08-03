# $NetBSD: dist.mk,v 1.17 2010/08/03 20:58:00 tnn2 Exp $
#
# used by wip/xulrunner/Makefile
# used by wip/firefox/Makefile

DISTNAME=	firefox-${FIREFOX_VER}.source
FIREFOX_VER=	4.0b2${MOZ_BRANCH_MINOR}
MOZ_BRANCH=	2.0b2
MOZ_BRANCH_MINOR=	# empty
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

DISTINFO_FILE=	${.CURDIR}/../../wip/xulrunner/distinfo
PATCHDIR=	${.CURDIR}/../../wip/xulrunner/patches

WRKSRC=		${WRKDIR}/mozilla-central

# snapshot overrides
#DISTNAME=	0e0e2516f04e
#MASTER_SITES=	http://hg.mozilla.org/mozilla-central/archive/
#WRKSRC=	${WRKDIR}/mozilla-central-0e0e2516f04e
