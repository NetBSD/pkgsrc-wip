# $NetBSD: Makefile,v 1.4 2010/01/18 09:38:35 thomasklausner Exp $
#

DISTNAME=	yakuake-2.9.4
PKGREVISION=	2
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

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdebase-runtime4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
