# $NetBSD: Makefile,v 1.1.1.1 2007/11/30 10:18:33 hfath Exp $
#

DISTNAME=	teapot-1.09
CATEGORIES=	math
MASTER_SITES=	http://www.moria.de/~michael/teapot/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://www.moria.de/~michael/teapot/
COMMENT=	Curses based spread sheet program

EGDIR=		${PREFIX}/share/examples/teapot
EXAMPLES=	examples/asqrt examples/asqrt.README examples/blink \
		examples/counter examples/counter.README examples/life \
		examples/life.README examples/graphtest.sh examples/sqrt \
		examples/sqrt.README
TEA_DOCSDIR=	${PREFIX}/share/doc/teapot
TEA_DOCS=	doc/teapot.doc doc/teapot.html doc/teapot.ps

do-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} ${MAKE_FLAGS} teapot
	cd ${WRKSRC}/doc && ${MAKE} teapot.doc teapot.html teapot.ps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/teapot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/teapot.1.en ${PREFIX}/${PKGMANDIR}/man1/teapot.1
	${INSTALL_DATA_DIR} ${EGDIR}
.for file in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${EGDIR}
.endfor
	${INSTALL_DATA_DIR} ${TEA_DOCSDIR}
.for file in ${TEA_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${TEA_DOCSDIR}
.endfor

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
