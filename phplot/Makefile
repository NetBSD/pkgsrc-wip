# $NetBSD: Makefile,v 1.1.1.1 2003/04/18 03:42:16 adrian_p Exp $

DISTNAME=	phplot-4.4.6
CATEGORIES=	graphics www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phplot/}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.phplot.com/
COMMENT=	PHP graph library

DEPENDS+=	php-gd>=4.0.0:../../graphics/php4-gd

NO_BUILD=	YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/phplot
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/phplot
	${INSTALL_DATA_DIR} ${PREFIX}/share/phplot
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.php \
		${PREFIX}/share/examples/phplot
	${INSTALL_DATA} ${WRKSRC}/examples/*.ttf \
		${PREFIX}/share/examples/phplot
	${INSTALL_DATA} ${WRKSRC}/examples/*.jpg \
		${PREFIX}/share/examples/phplot
	${INSTALL_DATA} ${WRKSRC}/*.txt \
		${PREFIX}/share/doc/phplot
	${INSTALL_DATA} ${WRKSRC}/doc/*.html \
		${PREFIX}/share/doc/phplot
	${INSTALL_SCRIPT} ${WRKSRC}/doc/*.php \
		${PREFIX}/share/doc/phplot
	${INSTALL_SCRIPT} ${WRKSRC}/*.php ${PREFIX}/share/phplot

.include "../../mk/bsd.pkg.mk"
