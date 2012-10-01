# $NetBSD: Makefile,v 1.2 2012/10/01 21:57:32 asau Exp $
#

DISTNAME=	kaffeine-1.2.2
CATEGORIES=	multimedia
MASTER_SITES=	http://sourceforge.net/projects/kaffeine/files/current/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kaffeine.kde.org/
COMMENT=	Full featured Multimedia-Player for KDE
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
