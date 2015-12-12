# $NetBSD: Makefile,v 1.1 2015/06/03 00:26:32 krytarowski Exp $

DISTNAME=	otter-browser-0.9.08
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=OtterBrowser/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://otter-browser.org/
COMMENT=	Project aiming to recreate classic Opera (12.x) UI using Qt5
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
