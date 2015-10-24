# $NetBSD: Makefile,v 1.1 2015/04/11 13:00:41 krytarowski Exp $

DISTNAME=	kwindowsystem-5.9.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://download.kde.org/stable/frameworks/5.9/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://projects.kde.org/projects/frameworks/kwindowsystem
COMMENT=	Access to the windowing system
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# don't leak buildlink reference in INTERFACE_INCLUDE_DIRECTORIES
# leaked by cmake find_package(X11), better fix welcome.
SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-configure
SUBST_MESSAGE.fix-paths=	Cleaning up INTERFACE_INCLUDE_DIRECTORIES
SUBST_FILES.fix-paths=		CMakeFiles/Export/lib/cmake/KF5WindowSystem/KF5WindowSystemTargets.cmake
SUBST_SED.fix-paths=		-e 's,${BUILDLINK_DIR},${X11BASE},g'

.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../wip/extra-cmake-modules/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
