# $NetBSD$

DISTNAME=	wadptr-3.8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=fragglet/}
GITHUB_PROJECT=	wadptr
GITHUB_TAG=	${DISTNAME}
EXTRACT_USING=	bsdtar

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://soulsphere.org/projects/wadptr/
COMMENT=	Command-line tool for compressing Doom WAD files
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

FORCE_C_STD=	c99
USE_TOOLS+=	bash gmake
REPLACE_BASH=	run_tests.sh

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPATH=${PREFIX}/${PKGMANDIR}
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
