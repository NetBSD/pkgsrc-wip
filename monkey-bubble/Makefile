# $NetBSD: Makefile,v 1.8 2004/08/17 18:31:08 tvierling Exp $
#

DISTNAME=		monkey-bubble-0.1.6
CATEGORIES=		games
MASTER_SITES=		http://monkey-bubble.tuxfamily.org/

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://monkey-bubble.tuxfamily.org/
COMMENT=		Bust'a'move clone written in C for GNOME2

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_LA_FILES+=	lib/libgdkview.la
LIBTOOL_LA_FILES+=	lib/libgstaudio.la
LIBTOOL_LA_FILES+=	lib/libmonkey.la
LIBTOOL_LA_FILES+=	lib/libmonkeyutil.la
LIBTOOL_LA_FILES+=	lib/libnetcltmonkey.la
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
