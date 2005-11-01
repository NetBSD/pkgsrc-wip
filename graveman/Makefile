# $NetBSD: Makefile,v 1.7 2005/11/01 21:24:30 leonardschmidt Exp $
#

DISTNAME=		graveman-0.3.12-4
CATEGORIES=		wip sysutils
MASTER_SITES=		http://graveman.tuxfamily.org/sources/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://graveman.tuxfamily.org/
COMMENT=		GTK2 frontend for CD writing and audio conversion

DEPENDS+=		dvd+rw-tools>5.21:../../sysutils/dvd+rw-tools

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

.include "options.mk"

BUILDLINK_DEPENDS.libglade2+=	libglade2>=2.4.0

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
