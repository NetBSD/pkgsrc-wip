# $NetBSD$

DISTNAME=	krename-5.0.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=KDE/}
GITHUB_PROJECT=	krename
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://userbase.kde.org/KRename
COMMENT=	Powerful batch file renamer for KDE
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/krename-5.0.0

USE_TOOLS=	msgmerge
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/kcrash/buildlink3.mk"
.include "../../graphics/kiconthemes/buildlink3.mk"
.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/kjobwidgets/buildlink3.mk"
.include "../../x11/kitemviews/buildlink3.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../www/kjs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
