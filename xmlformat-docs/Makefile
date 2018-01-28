# $NetBSD: Makefile,v 1.7 2014/10/09 14:06:32 thomasklausner Exp $
#

DISTNAME=		xmlformat-${XMLFORMAT_VERSION}
PKGNAME=		xmlformat-docs-${XMLFORMAT_VERSION}
CATEGORIES=		textproc
MASTER_SITES=		http://www.kitebird.com/software/xmlformat/

MAINTAINER=		mishka@NetBSD.org
HOMEPAGE=		http://www.kitebird.com/software/xmlformat/
COMMENT=		Configurable XML formatter, documentation files

NO_BUILD=		yes

DESCR_SRC=		${.CURDIR}/DESCR.common ${.CURDIR}/DESCR

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/xmlformat
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/xmlformat/examples
.for _dtype in xml html pdf
	${INSTALL_DATA} ${WRKSRC}/docs/tutorial.${_dtype} \
		${DESTDIR}${PREFIX}/share/doc/xmlformat
	${INSTALL_DATA} ${WRKSRC}/docs/xmlformat.${_dtype} \
		${DESTDIR}${PREFIX}/share/doc/xmlformat
.endfor
	${INSTALL_DATA} ${WRKSRC}/docs/API ${DESTDIR}${PREFIX}/share/doc/xmlformat
	${INSTALL_DATA} ${WRKSRC}/docs/xmlformat.conf \
		${DESTDIR}${PREFIX}/share/doc/xmlformat
	${INSTALL_DATA} ${WRKSRC}/docs/examples/* \
		${DESTDIR}${PREFIX}/share/doc/xmlformat/examples

.include "../../wip/xmlformat-docs/version.mk"
.include "../../mk/bsd.pkg.mk"
