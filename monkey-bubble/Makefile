# $NetBSD: Makefile,v 1.9 2004/09/23 05:59:54 jlamwww Exp $
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
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
