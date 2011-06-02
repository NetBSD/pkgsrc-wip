# $NetBSD: Makefile,v 1.1.1.1 2011/06/02 15:51:07 othyro Exp $
#

DISTNAME=	gbase-0.5
CATEGORIES=	math
MASTER_SITES=	http://www.fluxcode.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fluxcode.net/
COMMENT=	GTK program designed to convert between the four common bases
LICENSE=	artistic

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	gbase

CFLAGS+=	-I${BUILDLINK_PREFIX.gtk}/include/gtk-1.2 \
		-I${BUILDLINK_PREFIX.glib2}/include/glib/glib-2.0 \
		-I${BUILDLINK_PREFIX.glib2}/lib/glib-2.0/include \
		-I${BUILDLINK_PREFIX.cairo}/include/cairo \
		-I${BUILDLINK_PREFIX.pango}/include/pango-1.0 \
		-I${BUILDLINK_PREFIX.gtk}/lib \
		-I${BUILDLINK_PREFIX.atk}/include/atk-1.0

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/gbase ${DESTDIR}${PREFIX}/bin/gbase

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
