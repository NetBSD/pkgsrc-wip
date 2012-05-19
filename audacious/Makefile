# $NetBSD: Makefile,v 1.21 2012/05/19 05:49:14 lokivit Exp $
#

DISTNAME=	audacious-3.2.2
CATEGORIES=	wip
MASTER_SITES=	http://distfiles.audacious-media-player.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	loki.vt@gmail.com
HOMEPAGE=	http://audacious-media-player.org/
COMMENT=	Media player based on BMP and XMMS
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=  c c++
GNU_CONFIGURE=  YES
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=    YES
#LDFLAGS+=	-lglib2

CONFIGURE_ARGS+=	--enable-chardet --enable-nls
.include "options.mk"

PKGCONFIG_OVERRIDE+=	audacious.pc.in
PKGCONFIG_OVERRIDE+=	audclient.pc.in
.include "../../mk/bsd.options.mk"

LDFLAGS.DragonFly=      -lm -lX11 -lgmodule-2.0

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
#.include "../../devel/libmcs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../net/libmms/buildlink3.mk"
.include "../../devel/libmtp/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
