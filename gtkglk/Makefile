# $NetBSD: Makefile,v 1.5 2005/03/07 15:12:39 dillo Exp $
#

DISTNAME=	gtkglk-0.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IFARCHIVE:=programming/glk/implementations/}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://mirror.ifarchive.org/if-archiveXprogrammingXglkXimplementations.html
COMMENT=	Gtk+ 2 port of Glk interface for text adventures

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
BUILD_TARGET=	default

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
