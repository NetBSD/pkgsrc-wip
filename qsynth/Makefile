# $NetBSD$

DISTNAME=	qsynth-0.5.7
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qsynth/}
CATEGORIES=	audio

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://qsynth.sourceforge.io/qsynth-index.html
COMMENT=	Fluidsynth GUI frontend
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qtbase

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
