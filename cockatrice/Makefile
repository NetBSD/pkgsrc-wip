# $NetBSD$

DISTNAME=	cockatrice-2.8.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cockatrice/}
GITHUB_TAG=	2021-01-26-Release-${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://cockatrice.github.io/
COMMENT=	Virtual tabletop for multiplayer card games
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

WRKSRC=		${WRKDIR}/Cockatrice-${GITHUB_TAG}

CMAKE_ARGS+=	-DWITH_SERVER=0

.include "../../devel/protobuf/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtwebsockets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
