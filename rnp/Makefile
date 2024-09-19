# $NetBSD$

GITHUB_PROJECT=	rnp
GITHUB_TAG=	v0.12.0
DISTNAME=	rnp-0.12.0
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=riboseinc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/riboseinc/rnp/
COMMENT=	high performance C++ OpenPGP library
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/rnp-0.12.0
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	cmake/librnp.pc.in

.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
