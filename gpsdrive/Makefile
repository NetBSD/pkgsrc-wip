# $NetBSD: Makefile,v 1.7 2010/01/18 09:38:22 thomasklausner Exp $
#

DISTNAME=		gpsdrive-2.10pre4
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		http://www.gpsdrive.de/gpsdrive.tar/

MAINTAINER=		alnix@phear.org
HOMEPAGE=		http://www.gpsdrive.de/
COMMENT=		GpsDrive is a car (bike, ship, plane) navigation system

DEPENDS+=		wget>=1:../../net/wget
DEPENDS+=		pcre>=6.6:../../devel/pcre
DEPENDS+=		p5-libwww>=5.800:../../www/p5-libwww

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
PKG_DESTDIR_SUPPORT=	user-destdir
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
PTHREAD_AUTO_VARS=	YES	# XXX needed by mapnik / boost
USE_TOOLS+=		gmake msgfmt perl

# Disabling mysql doesn't seem to work.
.include "../../mk/mysql.buildlink3.mk"

#CONFIGURE_ARGS+=	--enable-dbus

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
#.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/mapnik/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
