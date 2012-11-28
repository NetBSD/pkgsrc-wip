# $NetBSD: Makefile,v 1.2 2012/11/28 20:25:54 christtrekker Exp $
#

DISTNAME=	razorqt-0.5.1
CATEGORIES=	x11
MASTER_SITES=	https://github.com/downloads/Razor-qt/razor-qt/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.razor-qt.org/
COMMENT=	Advanced, fast Qt environment without window manager
LICENSE=	gnu-gpl-v2

FETCH_USING=	curl
USE_LANGUAGES=	c c++
USE_TOOLS+=	bash
USE_CMAKE=	yes

REPLACE_BASH+=	razorqt-session/razor-session/resources/xdg-mime
REPLACE_BASH+=	razorqt-session/razor-session/resources/xdg-open
REPLACE_SH+=	razorqt-session/razor-session/resources/xdg-screensaver
CHECK_PORTABILITY_SKIP=	razorqt-session/razor-session/resources/xdg-screensaver

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/xscreensaver/buildlink3.mk"
# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
