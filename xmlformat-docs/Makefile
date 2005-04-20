# $NetBSD: Makefile,v 1.1.1.1 2005/04/20 14:38:26 bubuchka Exp $
#

DISTNAME=		xmlformat-1.03
PKGNAME=		xmlformat-docs-1.03
CATEGORIES=		textproc wip
MASTER_SITES=		http://www.kitebird.com/software/xmlformat/

MAINTAINER=		mishka@apk.od.ua
HOMEPAGE=		http://www.kitebird.com/software/xmlformat/
COMMENT=		Configurable XML formatter, documentation files

NO_BUILD=		yes
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DESCR_SRC=		${.CURDIR}/DESCR.common ${.CURDIR}/DESCR

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xmlformat
.	for _dtype in xml html pdf
	${INSTALL_DATA} ${WRKSRC}/docs/tutorial.${_dtype} \
		${PREFIX}/share/doc/xmlformat
	${INSTALL_DATA} ${WRKSRC}/docs/xmlformat.${_dtype} \
		${PREFIX}/share/doc/xmlformat
.	endfor
	${INSTALL_DATA} ${WRKSRC}/docs/API ${PREFIX}/share/doc/xmlformat
	${INSTALL_DATA} ${WRKSRC}/docs/xmlformat.conf \
		${PREFIX}/share/doc/xmlformat

.include "../../mk/bsd.pkg.mk"
