# $NetBSD: dist.mk,v 1.30 2011/07/07 14:22:13 tnn2 Exp $
#
# used by wip/xulrunner/Makefile
# used by wip/firefox/Makefile

DISTNAME=	firefox-${FIREFOX_VER}.source
FIREFOX_VER=	${MOZ_BRANCH}${MOZ_BRANCH_MINOR}
MOZ_BRANCH=	5.0
MOZ_BRANCH_MINOR=	# empty
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

DISTINFO_FILE=	${.CURDIR}/../../wip/xulrunner/distinfo
PATCHDIR=	${.CURDIR}/../../wip/xulrunner/patches

WRKSRC=		${WRKDIR}/mozilla-release

# snapshot overrides
#DISTNAME=	ea8b7e3f457b
#MASTER_SITES=	http://hg.mozilla.org/mozilla-aurora/archive/
#WRKSRC=		${WRKDIR}/mozilla-aurora-${DISTNAME}
