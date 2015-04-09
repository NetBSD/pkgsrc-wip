# $NetBSD: Makefile,v 1.7 2015/04/09 22:07:26 krytarowski Exp $

DISTNAME=	gnome-main-menu-1.8.0
CATEGORIES=	x11
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.8/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	MATE Desktop main menu
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

.include "../../devel/glib2/schemas.mk"

.include "../../wip/mate-panel/buildlink3.mk"
.include "../../wip/mate-desktop/buildlink3.mk"
.include "../../wip/mate-control-center/buildlink3.mk"
.include "../../wip/caja/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
