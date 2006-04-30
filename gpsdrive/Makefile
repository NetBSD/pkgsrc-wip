# $NetBSD: Makefile,v 1.1.1.2 2006/04/30 19:26:49 alnix Exp $
#

DISTNAME=		gpsdrive-2.09
CATEGORIES=		geography
MASTER_SITES=		http://www.gpsdrive.cc/

MAINTAINER=		alnix@phear.org
HOMEPAGE=		http://www.gpsdrive.cc/
COMMENT=		GpsDrive is a car (bike, ship, plane) navigation system

#DEPENDS+=		gpsd>=1.07:../../geography/gpsd
DEPENDS+=		wget>=1:../../net/wget
DEPENDS+=		pcre>=6.6:../../devel/pcre

GNU_CONFIGURE=		YES

WRKSRC=			${WRKDIR}/gpsdrive-2.09
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

# XXX make this an option
CONFIGURE_ARGS+=	--disable-mysql

.include "../../mk/bsd.prefs.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
#.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
