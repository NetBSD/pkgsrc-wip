# $NetBSD$

GITHUB_PROJECT=	xtensor
DISTNAME=	0.19.4
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=QuantStack/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://quantstack.net/xtensor.html
COMMENT=	Multi-dimensional arrays with broadcasting and lazy computing
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/xtensor-0.19.4
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	xtensor.pc.in

.include "../../wip/xtl-quant-stack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
