# $NetBSD: Makefile,v 1.6 2010/06/13 22:46:57 thomasklausner Exp $
#

DISTNAME=	beryl-settings-${BERYL_VERSION}
PKGREVISION=	4
CATEGORIES=	wm

COMMENT=	Beryl settings bindings

.include "../../wip/beryl/Makefile.inc"

MAKE_JOBS_SAFE=	no

USE_PKGLOCALEDIR=	yes

USE_TOOLS+=	gettext-tools
USE_TOOLS+=	intltool

#PKG_CONFIG_PATH=${BUILDLINK_PREFIX.beryl-settings-bindings}/lib/pkgconfig

PYTHON_PATCH_SCRIPTS+=src/beryl-settings.in


CONFIGURE_ENV+=	PKG_CONFIG_PATH=${PKG_CONFIG_PATH:Q}

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-[3-4]*)
CFLAGS+= -fno-strict-aliasing
.endif

.include "../../lang/python/application.mk"

.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../wip/beryl-settings-bindings/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"


.include "../../mk/bsd.pkg.mk"
