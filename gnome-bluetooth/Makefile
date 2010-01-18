# $NetBSD: Makefile,v 1.16 2010/01/18 09:38:22 thomasklausner Exp $
#

DISTNAME=		gnome-bluetooth-0.7.0
PKGREVISION=		5
CATEGORIES=		net
MASTER_SITES=		http://ftp.gnome.org/pub/gnome/sources/gnome-bluetooth/0.7/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://live.gnome.org/GnomeBluetooth
COMMENT=		Gnome Bluetooth Manager

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gnome-bluetooth.pc.in
GNU_CONFIGURE=		yes

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/gob2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../wip/libbtctl/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
