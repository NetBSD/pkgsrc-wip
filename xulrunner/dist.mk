# $NetBSD: dist.mk,v 1.11 2010/03/16 20:12:06 tnn2 Exp $
#
# used by wip/xulrunner/Makefile
# used by wip/firefox/Makefile

DISTNAME=	firefox-${FIREFOX_VER}.source
FIREFOX_VER=	3.7a4pre${MOZ_BRANCH_MINOR}
MOZ_BRANCH=	1.9.3a4pre
MOZ_BRANCH_MINOR=	# empty
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

DISTINFO_FILE=	${.CURDIR}/../../wip/xulrunner/distinfo
PATCHDIR=	${.CURDIR}/../../wip/xulrunner/patches

WRKSRC=		${WRKDIR}/mozilla-${MOZ_BRANCH}

# snapshot overrides
DISTNAME=	050887c64183
MASTER_SITES=	http://hg.mozilla.org/mozilla-central/archive/
WRKSRC=		${WRKDIR}/mozilla-central-050887c64183
