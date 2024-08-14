# $NetBSD$

DISTNAME=	wadgadget-0.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=fragglet/}
GITHUB_TAG=	${DISTNAME}
GITHUB_PROJECT=	WadGadget

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://github.com/fragglet/WadGadget/
COMMENT=	WAD file editor for Doom engine games
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

USE_CC_FEATURES=	c99
USE_TOOLS+=		gmake pkg-config

WRKSRC=			${WRKDIR}/WadGadget-wadgadget-0.1/src
REPLACE_PYTHON=		help/make_help.py
INSTALLATION_DIRS=	bin

MAKE_FILE=		GNUmakefile
BUILD_TARGET=		wadgadget

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wadgadget ${DESTDIR}${PREFIX}/bin/

PYTHON_VERSIONS_ACCEPTED=	312 311 310
.include "../../lang/python/tool.mk"

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../graphics/libsixel/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
