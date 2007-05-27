# $NetBSD: Makefile,v 1.2 2007/05/27 06:51:50 bsadewitz Exp $
#

DISTNAME=	beryl-plugins-${BERYL_VERSION}
CATEGORIES=	wm

COMMENT=	Supported plugins for the Beryl compositor

.include "../../wip/beryl/Makefile.inc"

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes

USE_TOOLS+=     perl
USE_TOOLS+=     gettext-tools
USE_TOOLS+=     intltool
USE_LIBTOOL+=	yes

.include "../../wip/beryl-core/buildlink3.mk"
.include "../../wip/beryl-settings/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
