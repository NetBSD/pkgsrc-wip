# $NetBSD: Makefile,v 1.2 2005/04/20 11:35:40 bubuchka Exp $
#

DISTNAME=		xmlformat-1.03
PKGREVISION=		1
CATEGORIES=		textproc wip
MASTER_SITES=		http://www.kitebird.com/software/xmlformat/

MAINTAINER=		mishka@apk.od.ua
HOMEPAGE=		http://www.kitebird.com/software/xmlformat/
COMMENT=		Configurable XML formatter (pretty-printer)

USE_PERL5=		run
REPLACE_PERL=		xmlformat.pl

NO_BUILD=		yes
PKG_INSTALLATION_TYPES=	overwrite pkgviews

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmlformat.pl ${PREFIX}/bin/xmlformat

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xmlformat
	${INSTALL_DATA} ${WRKSRC}/docs/API ${PREFIX}/share/doc/xmlformat
.	for _dtype in xml html pdf
	${INSTALL_DATA} ${WRKSRC}/docs/tutorial.${_dtype} \
		${PREFIX}/share/doc/xmlformat
	${INSTALL_DATA} ${WRKSRC}/docs/xmlformat.${_dtype} \
		${PREFIX}/share/doc/xmlformat
.	endfor

	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xmlformat
	${INSTALL_DATA} ${WRKSRC}/docs/xmlformat.conf \
		${PREFIX}/share/examples/xmlformat
	${INSTALL_DATA} ${WRKSRC}/docs/examples/* \
		${PREFIX}/share/examples/xmlformat

.include "../../mk/bsd.pkg.mk"
