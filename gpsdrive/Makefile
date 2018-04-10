# $NetBSD: Makefile,v 1.10 2012/11/13 20:09:31 othyro Exp $
#

DISTNAME=		gpsdrive-2.10pre4
PKGREVISION=		3
CATEGORIES=		geography
MASTER_SITES=		http://www.gpsdrive.de/gpsdrive.tar/
LICENSE=		gnu-gpl-v2

MAINTAINER=		alnix@phear.org
HOMEPAGE=		http://www.gpsdrive.de/
COMMENT=		GpsDrive is a car (bike, ship, plane) navigation system

DEPENDS+=		wget>=1:../../net/wget
DEPENDS+=		pcre>=6.6:../../devel/pcre
DEPENDS+=		p5-libwww>=5.800:../../www/p5-libwww

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
PTHREAD_AUTO_VARS=	YES	# XXX needed by mapnik / boost
USE_TOOLS+=		gmake msgfmt perl

# Disabling mysql doesn't seem to work.
.include "../../mk/mysql.buildlink3.mk"

#CONFIGURE_ARGS+=	--enable-dbus

.include "options.mk"


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
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
