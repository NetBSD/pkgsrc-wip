# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	gwenview-${KAPPSVER}
CATEGORIES=	graphics

HOMEPAGE=	http://kde.org/applications/graphics/gwenview/
COMMENT=	KDE image viewer
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../wip/kde5/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	kimageformats>=5.19.0:../../graphics/kimageformats

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/cfitsio/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/baloo5/buildlink3.mk"
.include "../../x11/kactivities5/buildlink3.mk"
.include "../../x11/kdelibs4support/buildlink3.mk"
.include "../../wip/libkdcraw/buildlink3.mk"
#.include "../../wip/libkipi5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtimageformats/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
