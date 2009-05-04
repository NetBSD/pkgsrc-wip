# $NetBSD: Makefile,v 1.1.1.1 2009/05/04 16:19:49 msorc Exp $
#

DISTNAME=	yakuake-2.9.4
CATEGORIES=	x11
MASTER_SITES=	http://download.berlios.de/yakuake/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	drjumba@bigmir.net
HOMEPAGE=	http://extragear.kde.org/apps/yakuake/
COMMENT=	Drop-down terminal emulator based on KDE Konsole technology

PKG_DESTDIR_SUPPORT=    user-destdir

USE_CMAKE=              yes
USE_LANGUAGES=          c c++
USE_TOOLS+=             awk msgfmt pkg-config perl


# url2pkg-marker (please do not remove this line.)
.include "../../wip/kde4/kde4.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
