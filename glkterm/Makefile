# $NetBSD: Makefile,v 1.2 2004/05/09 23:09:28 dillo Exp $
#

DISTNAME=	glkterm-078
PKGNAME=	glkterm-0.7.8
WRKSRC=		${WRKDIR}/glkterm
CATEGORIES=	games
MASTER_SITES=	http://mirror.ifarchive.org/if-archive/programming/glk/implementations/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.eblong.com/zarf/glk/index.html
COMMENT=	Curses port of Glk interface

# uses halfkey (present since 1.6M)
INCOMPAT_CURSES+=	NetBSD-1.4[Y-Z]* NetBSD-1.5* NetBSD-1.6-* NetBSD-1.6.*
INCOMPAT_CURSES+=	NetBSD-1.6[A-L]*

USE_BUILDLINK3=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/glkterm
	for f in Make.glkterm gi_blorb.h gi_dispa.h glk.h glkstart.h; \
	do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/include/glkterm; \
	done
	${INSTALL_DATA} ${WRKSRC}/libglkterm.a ${PREFIX}/lib

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
