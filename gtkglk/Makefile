# $NetBSD: Makefile,v 1.9 2006/06/12 16:28:56 thomasklausner Exp $
#

DISTNAME=	gtkglk-0.2
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IFARCHIVE:=programming/glk/implementations/}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.ifarchive.org/indexes/if-archiveXprogrammingXglkXimplementations.html
COMMENT=	Gtk+ 2 port of Glk interface for text adventures

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
BUILD_TARGET=	default

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
