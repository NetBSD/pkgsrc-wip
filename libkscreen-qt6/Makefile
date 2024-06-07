# $NetBSD$

DISTNAME=	libkscreen-6.0.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_KDE:=plasma/6.0.5/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://invent.kde.org/plasma/libkscreen
COMMENT=	KDE screen management software
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

TOOL_DEPENDS+=	extra-cmake-modules>=6.2.0:../../devel/extra-cmake-modules
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../wip/kwayland-qt6/buildlink3.mk"
.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
