# $NetBSD$

DISTNAME=	arachne-pnr-e97e35c
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=cseed/}
GITHUB_TAG=	e97e35c3de200083b1f420d314df166326fc48e8

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cseed/
COMMENT=	Place and route tool for FPGAs
LICENSE=	mit

USE_LANGUAGES+=		c++
USE_TOOLS+=		gmake
LIBS+=			-lm
DEPENDS+=		icestorm-[0-9]*:../../wip/icestorm-git

WRKSRC=			${WRKDIR}/arachne-pnr-${GITHUB_TAG}
MAKE_ENV+=		ICEBOX=${PREFIX}/share/icebox
MAKE_ENV+=		DESTDIR=${DESTDIR}
MAKE_ENV+=		PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
