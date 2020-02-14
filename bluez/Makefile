# $NetBSD$

DISTNAME=	bluez-5.52
CATEGORIES=	net
MASTER_SITES=	https://mirrors.edge.kernel.org/pub/linux/bluetooth/

MAINTAINER=	nykula@ukr.net
HOMEPAGE=	http://www.bluez.org/
COMMENT=	Bluetooth scan, pair, connect and power toggle
LICENSE=	gnu-gpl-v2

CONFLICTS=		bluez-libs # v3
ONLY_FOR_PLATFORM=	Linux-*-*
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-obex --disable-systemd --disable-udev
CONFIGURE_ARGS+=	--disable-tools --enable-library

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
