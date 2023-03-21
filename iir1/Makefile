# $NetBSD$

DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=berndporr/}
GITHUB_PROJECT=	iir1
GITHUB_TAG=	1.9.4
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://berndporr.github.io/iir1/
COMMENT=	DSP IIR Realtime C++ filter library
LICENSE=	mit

WRKSRC=		${WRKDIR}/iir1-1.9.4
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	iir.pc.in

.include "../../mk/bsd.pkg.mk"
