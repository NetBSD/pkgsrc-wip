# $NetBSD: Makefile,v 1.7 2015/04/09 22:07:26 krytarowski Exp $

DISTNAME=	caja-1.12.6
CATEGORIES=	sysutils
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.12/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	File manager for the MATE desktop
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

BUILD_DEPENDS+=		gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	libcaja-extension/libcaja-extension.pc.in

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

.include "../../wip/mate-desktop/buildlink3.mk"
.include "../../devel/exempi/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pangox-compat/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
