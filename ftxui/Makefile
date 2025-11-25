# $NetBSD$

FTXVER=		6.1.9
DISTNAME=	FTXUI-${FTXVER}
PKGNAME=	ftxui-${FTXVER}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ArthurSonzogni/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ArthurSonzogni/FTXUI/
COMMENT=	C++ Functional Terminal User Interface
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c++

PKGCONFIG_OVERRIDE+=	ftxui.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
