# $NetBSD: Makefile,v 1.22 2013/02/25 01:39:41 othyro Exp $
#

DISTNAME=	gnome-bluetooth-3.7.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-bluetooth/3.7/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://live.gnome.org/GnomeBluetooth
COMMENT=	Fork of bluez-gnome focused on integration with GNOME
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

ONLY_FOR_PLATFORM=	Linux-*-*

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt msgmerge perl pkg-config xgettext
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gnome-bluetooth-1.0.pc.in
GNU_CONFIGURE=		yes

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
