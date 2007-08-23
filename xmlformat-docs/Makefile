# $NetBSD: Makefile,v 1.4 2007/08/23 13:45:53 bubuchka Exp $
#

DISTNAME=		xmlformat-${XMLFORMAT_VERSION}
PKGNAME=		xmlformat-docs-${XMLFORMAT_VERSION}
CATEGORIES=		textproc
MASTER_SITES=		http://www.kitebird.com/software/xmlformat/

MAINTAINER=		mishka@apk.od.ua
HOMEPAGE=		http://www.kitebird.com/software/xmlformat/
COMMENT=		Configurable XML formatter, documentation files

NO_BUILD=		yes
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DESCR_SRC=		${.CURDIR}/DESCR.common ${.CURDIR}/DESCR

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xmlformat
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xmlformat/examples
.	for _dtype in xml html pdf
	${INSTALL_DATA} ${WRKSRC}/docs/tutorial.${_dtype} \
		${PREFIX}/share/doc/xmlformat
	${INSTALL_DATA} ${WRKSRC}/docs/xmlformat.${_dtype} \
		${PREFIX}/share/doc/xmlformat
.	endfor
	${INSTALL_DATA} ${WRKSRC}/docs/API ${PREFIX}/share/doc/xmlformat
	${INSTALL_DATA} ${WRKSRC}/docs/xmlformat.conf \
		${PREFIX}/share/doc/xmlformat
	${INSTALL_DATA} ${WRKSRC}/docs/examples/* \
		${PREFIX}/share/doc/xmlformat/examples

.include "../../wip/xmlformat-docs/version.mk"
.include "../../mk/bsd.pkg.mk"
