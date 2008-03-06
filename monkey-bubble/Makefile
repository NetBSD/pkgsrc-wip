# $NetBSD: Makefile,v 1.16 2008/03/06 14:54:09 thomasklausner Exp $
#

DISTNAME=		monkey-bubble-0.1.6
PKGREVISION=		4
CATEGORIES=		games
MASTER_SITES=		http://monkey-bubble.tuxfamily.org/

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://monkey-bubble.tuxfamily.org/
COMMENT=		Bust'a'move clone written in C for GNOME2

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../graphics/librsvg/buildlink3.mk"
.include "../../multimedia/gstreamer0.8/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
