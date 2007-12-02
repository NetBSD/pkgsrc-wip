# $NetBSD: Makefile,v 1.13 2007/12/02 02:44:31 hoka_adam Exp $
#

DISTNAME=		graveman-0.3.12-5
CATEGORIES=		sysutils
MASTER_SITES=		http://graveman.tuxfamily.org/sources/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://graveman.tuxfamily.org/
COMMENT=		GTK2 frontend for CD writing and audio conversion

DEPENDS+=		dvd+rw-tools>5.21:../../sysutils/dvd+rw-tools

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.2
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool pkg-config

.include "options.mk"

BUILDLINK_API_DEPENDS.libglade+=	libglade>=2.4.0

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
