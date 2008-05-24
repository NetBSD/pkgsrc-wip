# $NetBSD: Makefile,v 1.2 2008/05/24 15:34:08 tnn2 Exp $
#

DISTNAME=	beryl-manager-${BERYL_VERSION}
CATEGORIES=	wm

COMMENT=	Managing application of the Beryl compositing window manager

.include "../../wip/beryl/Makefile.inc"

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes

USE_TOOLS+=	perl
USE_TOOLS+=	gettext-tools
USE_TOOLS+=	intltool
USE_LIBTOOL+=	yes

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
