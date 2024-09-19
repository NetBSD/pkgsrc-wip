# $NetBSD$

GITHUB_PROJECT=	heaptrack
GITHUB_TAG=	v1.2.0
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=KDE/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/KDE/heaptrack/
COMMENT=	Heap memory profiler
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/heaptrack-1.2.0

USE_CMAKE=	yes
USE_TOOLS=      msgmerge
USE_LANGUAGES=	c c++

DEPENDS+=	kqtquickcharts>=20.04.1:../../graphics/kqtquickcharts

.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../devel/kitemmodels/buildlink3.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../devel/threadweaver/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../security/kauth/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/solid/buildlink3.mk"
.include "../../textproc/kcodecs/buildlink3.mk"
.include "../../textproc/kcompletion/buildlink3.mk"
.include "../../x11/kitemviews/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/kwindowsystem/buildlink3.mk"
.include "../../x11/kjobwidgets/buildlink3.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
