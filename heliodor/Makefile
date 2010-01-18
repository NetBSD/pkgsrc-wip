# $NetBSD: Makefile,v 1.4 2010/01/18 09:38:24 thomasklausner Exp $
#

DISTNAME=	heliodor-0.2.1
PKGREVISION=	2

.include "../../wip/beryl/Makefile.inc"

COMMENT=	Heliodor theme package for beryl

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../x11/gnome-control-center/buildlink3.mk"

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../wip/beryl-core/buildlink3.mk"
.include "../../wm/metacity/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
