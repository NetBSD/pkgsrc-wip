# $NetBSD: Makefile,v 1.4 2012/09/24 17:14:28 asau Exp $
#

DISTNAME=	beryl-manager-${BERYL_VERSION}
PKGREVISION=	1
CATEGORIES=	wm

COMMENT=	Managing application of the Beryl compositing window manager

.include "../../wip/beryl/Makefile.inc"

USE_PKGLOCALEDIR=	yes

USE_TOOLS+=	perl
USE_TOOLS+=	gettext-tools
USE_TOOLS+=	intltool
USE_LIBTOOL+=	yes

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
