# $NetBSD$

DISTNAME=	icestorm-ce4e1bc
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=cliffordwolf/}
GITHUB_TAG= 	ce4e1bcfd8c791fe3fb6f991fbfaed309bc1f5ad

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cliffordwolf/
COMMENT=	Project IceStorm
LICENSE=	mit

USE_LANGUAGES+=		c c++
USE_TOOLS+= 		pkg-config gmake
LIBS+= 			-lm -lstdc++

WRKSRC=			${WRKDIR}/icestorm-${GITHUB_TAG}

.include "../../lang/python34/buildlink3.mk"
.include "../../devel/libftdi/buildlink3.mk"
#.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
