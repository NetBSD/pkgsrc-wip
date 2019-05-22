# $NetBSD$

GITHUB_PROJECT=	avra
DISTNAME=	1.4.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=hsoft/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://github.com/hsoft/avra/
COMMENT=	Assember for the Atmel AVR microcontroller family
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

WRKSRC=	${WRKDIR}/avra-${DISTNAME}

.include "../../mk/bsd.pkg.mk"
