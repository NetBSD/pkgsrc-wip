# $NetBSD: Makefile,v 1.1 2007/04/25 07:07:58 bsadewitz Exp $
#

DISTNAME=	beryl-settings-${BERYL_VERSION}
CATEGORIES=	wm

COMMENT=	Beryl settings bindings

.include "../../wip/beryl/Makefile.inc"

MAKE_JOBS_SAFE=	no

USE_PKGLOCALEDIR=	yes

USE_TOOLS+=	gettext-tools
USE_TOOLS+=	intltool

PKG_CONFIG_PATH=${BUILDLINK_PREFIX.beryl-settings-bindings}/lib/pkgconfig


CONFIGURE_ENV+=	PKG_CONFIG_PATH=${PKG_CONFIG_PATH:Q}


.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../wip/beryl-settings-bindings/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"


.include "../../mk/bsd.pkg.mk"
