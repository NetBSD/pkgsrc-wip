# $NetBSD: dist.mk,v 1.7 2010/02/16 14:46:58 tnn2 Exp $
#
# used by wip/xulrunner/Makefile
# used by wip/firefox/Makefile

DISTNAME=	firefox-${FIREFOX_VER}.source
FIREFOX_VER=	3.6${MOZ_BRANCH_MINOR}
MOZ_BRANCH=	1.9.2
MOZ_BRANCH_MINOR=	.2pre
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

DISTINFO_FILE=	${.CURDIR}/../../wip/xulrunner/distinfo
PATCHDIR=	${.CURDIR}/../../wip/xulrunner/patches

WRKSRC=		${WRKDIR}/mozilla-${MOZ_BRANCH}

# snapshot overrides
DISTNAME=	14fd499129bf
MASTER_SITES=	http://hg.mozilla.org/releases/mozilla-1.9.2/archive/
WRKSRC=		${WRKDIR}/mozilla-1-9-2-14fd499129bf
