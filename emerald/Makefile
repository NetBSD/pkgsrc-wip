# $NetBSD: Makefile,v 1.3 2012/09/28 22:07:33 asau Exp $
#

DISTNAME=	emerald-0.2.1
PKGREVISION=	1
COMMENT=	Emerald decorator for the Beryl Compositor

.include "../../wip/beryl/Makefile.inc"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gettext-tools

PKGCONFIG_OVERRIDE+=	libengine/emeraldengine.pc.in

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/shared-mime-info/mimedb.mk"

.include "../../wip/beryl-core/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
