# $NetBSD: dist.mk,v 1.15 2010/05/31 09:24:03 tnn2 Exp $
#
# used by wip/xulrunner/Makefile
# used by wip/firefox/Makefile

DISTNAME=	firefox-${FIREFOX_VER}.source
FIREFOX_VER=	3.7a5pre${MOZ_BRANCH_MINOR}
MOZ_BRANCH=	1.9.3a5pre
MOZ_BRANCH_MINOR=	# empty
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

DISTINFO_FILE=	${.CURDIR}/../../wip/xulrunner/distinfo
PATCHDIR=	${.CURDIR}/../../wip/xulrunner/patches

WRKSRC=		${WRKDIR}/mozilla-${MOZ_BRANCH}

# snapshot overrides
DISTNAME=	e73cbd31c93e
MASTER_SITES=	http://hg.mozilla.org/mozilla-central/archive/
WRKSRC=		${WRKDIR}/mozilla-central-e73cbd31c93e
