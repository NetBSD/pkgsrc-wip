# $NetBSD: Makefile,v 1.1.1.1 2005/12/20 16:09:57 lkundrak Exp $

DISTNAME=		c2html-20050617
CATEGORIES=		textproc devel
MASTER_SITES=		http://gavare.se/c2html/src/

MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://gavare.se/c2html/src/
COMMENT=		Converts a C source tree to hyperlinked and colored HTML

do-install:
	${INSTALL_PROGRAM}	${WRKSRC}/c2html ${PREFIX}/bin
	${INSTALL_DATA_DIR}	${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA}		${WRKSRC}/README ${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
