# $NetBSD$

DISTNAME=	cockatrice-${PKGVERSION_NOREV}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cockatrice/}
GITHUB_TAG=	2025-04-03-Release-${PKGVERSION_NOREV}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

WRKSRC=		${WRKDIR}/Cockatrice-${GITHUB_TAG}

.include "../../devel/protobuf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebsockets/buildlink3.mk"
