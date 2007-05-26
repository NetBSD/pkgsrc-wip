# $NetBSD: Makefile,v 1.3 2007/05/26 21:52:52 bsadewitz Exp $
#

DISTNAME=	beryl-settings-${BERYL_VERSION}
PKGREVISION=	1
CATEGORIES=	wm

COMMENT=	Beryl settings bindings

.include "../../wip/beryl/Makefile.inc"

MAKE_JOBS_SAFE=	no

USE_PKGLOCALEDIR=	yes

USE_TOOLS+=	gettext-tools
USE_TOOLS+=	intltool

PKG_CONFIG_PATH=${BUILDLINK_PREFIX.beryl-settings-bindings}/lib/pkgconfig


CONFIGURE_ENV+=	PKG_CONFIG_PATH=${PKG_CONFIG_PATH:Q}

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-[3-4]*)
CFLAGS+= -fno-strict-aliasing
.endif



.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../wip/beryl-settings-bindings/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"


.include "../../mk/bsd.pkg.mk"
