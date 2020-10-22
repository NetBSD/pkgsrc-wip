# $NetBSD$

GITHUB_PROJECT=	spectacle
GITHUB_TAG=	v20.08.1
DISTNAME=	v20.08.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=KDE/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://apps.kde.org/en/spectacle
COMMENT=	Screenshot taking utility for the KDE desktop
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/spectacle-20.08.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../devel/ki18n/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../devel/knotifications/buildlink3.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../devel/kwayland/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../security/kauth/buildlink3.mk"
.include "../../sysutils/solid/buildlink3.mk"
.include "../../textproc/kcodecs/buildlink3.mk"
.include "../../textproc/kcompletion/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/kconfigwidgets/buildlink3.mk"
.include "../../x11/kitemviews/buildlink3.mk"
.include "../../x11/kjobwidgets/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtwayland/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
