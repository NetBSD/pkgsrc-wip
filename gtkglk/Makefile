# $NetBSD: Makefile,v 1.3 2004/12/02 16:39:00 thomasklausner Exp $
#

DISTNAME=	gtkglk-0.2
CATEGORIES=	games
MASTER_SITES=	http://www.ifarchive.org/if-archive/programming/glk/implementations/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.ifarchive.org/if-archive/programming/glk/implementations/
COMMENT=	Gtk+ 2 port of Glk interface for text adventures

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
BUILD_TARGET=	default

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/gtkglk
	for f in Make.gtkglk gi_blorb.h gi_dispa.h glk.h glkstart.h; \
	do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/include/gtkglk; \
	done

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
