# $NetBSD$

GITHUB_PROJECT=	xtl
DISTNAME=	0.6.1
PKGNAME=	${GITHUB_PROJECT}-quant-stack-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=QuantStack/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/QuantStack/xtl
COMMENT=	Template library that supports other quantstack projects
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/xtl-0.6.1
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	xtl.pc.in

.include "../../mk/bsd.pkg.mk"
