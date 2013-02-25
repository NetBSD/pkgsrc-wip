# $NetBSD: Makefile,v 1.21 2013/02/25 01:28:34 othyro Exp $
#

DISTNAME=	gnome-bluetooth-3.7.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-bluetooth/3.7/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/GnomeBluetooth
COMMENT=	Gnome Bluetooth Manager
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

#ONLY_FOR_PLATFORM=	Linux-*-*

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt msgmerge pkg-config xgettext
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
#.include "../../devel/GConf/buildlink3.mk"
#.include "../../devel/libgnome/buildlink3.mk"
#.include "../../devel/libgnomeui/buildlink3.mk"
#.include "../../devel/libglade/buildlink3.mk"
#.include "../../devel/gob2/buildlink3.mk"
#.include "../../graphics/librsvg/buildlink3.mk"
#.include "../../net/ORBit2/buildlink3.mk"
#.include "../../security/gnutls/buildlink3.mk"
#.include "../../security/gnome-keyring/buildlink3.mk"
#.include "../../sysutils/gnome-vfs/buildlink3.mk"
#.include "../../wip/libbtctl/buildlink3.mk"
#.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
