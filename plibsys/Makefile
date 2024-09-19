# $NetBSD$

GITHUB_PROJECT=	plibsys
DISTNAME=	0.0.3
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=saprykin/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/saprykin/plibsys/
COMMENT=	Highly portable C system library
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}/plibsys-0.0.3
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
