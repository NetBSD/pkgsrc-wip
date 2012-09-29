# $NetBSD: Makefile,v 1.6 2012/09/29 17:05:54 asau Exp $
#

DISTNAME=	heliodor-0.2.1
PKGREVISION=	3

.include "../../wip/beryl/Makefile.inc"

COMMENT=	Heliodor theme package for beryl

PKG_DESTDIR_SUPPORT=	none

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../x11/gnome-control-center/buildlink3.mk"

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../wip/beryl-core/buildlink3.mk"
.include "../../wm/metacity/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
