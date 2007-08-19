# $NetBSD: Makefile,v 1.5 2007/08/19 21:10:26 tnn2 Exp $
#

DISTNAME=		gpsdrive-2.09
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		http://www.gpsdrive.de/gpsdrive.tar/

MAINTAINER=		alnix@phear.org
HOMEPAGE=		http://www.gpsdrive.de/
COMMENT=		GpsDrive is a car (bike, ship, plane) navigation system

DEPENDS+=		wget>=1:../../net/wget
DEPENDS+=		pcre>=6.6:../../devel/pcre

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/gpsdrive-2.09
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		msgfmt

# XXX make this an option
CONFIGURE_ARGS+=	--disable-mysql

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
#.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
