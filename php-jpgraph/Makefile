# $NetBSD: Makefile,v 1.1.1.1 2003/07/08 09:44:16 adrian_p Exp $

DISTNAME=	jpgraph-1.11
CATEGORIES=	graphics www
MASTER_SITES=	http://www.aditus.nu/jpgraph/downloads/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.aditus.nu/jpgraph/index.php
COMMENT=	JpGraph is an OO class library for PHP

DEPENDS+=	php-gd>=4.1:../../graphics/php4-gd

LICENSE=        jpgraph-license

NO_BUILD=	YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/jpgraph
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jpgraph
	${INSTALL_DATA_DIR} ${PREFIX}/share/jpgraph
	${INSTALL_DATA_DIR} ${PREFIX}/share/jpgraph/utils
	${INSTALL_DATA_DIR} ${PREFIX}/share/jpgraph/utils/misc
	${INSTALL_DATA_DIR} ${PREFIX}/share/jpgraph/utils/jpdocgen

	${INSTALL_SCRIPT} ${WRKSRC}/src/Examples/*.php \
		${PREFIX}/share/examples/jpgraph
	${INSTALL_DATA} ${WRKSRC}/src/Examples/*.png \
		${PREFIX}/share/examples/jpgraph
	${INSTALL_DATA} ${WRKSRC}/src/Examples/*.gif \
		${PREFIX}/share/examples/jpgraph
	${INSTALL_DATA} ${WRKSRC}/src/Examples/*.jpg \
		${PREFIX}/share/examples/jpgraph

	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/jpgraph
	${INSTALL_DATA} ${WRKSRC}/QPL.txt ${PREFIX}/share/doc/jpgraph
	${INSTALL_DATA} ${WRKSRC}/src/Changelog ${PREFIX}/share/doc/jpgraph

	${INSTALL_SCRIPT} ${WRKSRC}/src/*.php ${PREFIX}/share/jpgraph

	${INSTALL_DATA} ${WRKSRC}/src/utils/Readme \
		${PREFIX}/share/jpgraph/utils
	${INSTALL_SCRIPT} ${WRKSRC}/src/utils/misc/*.php \
		${PREFIX}/share/jpgraph/utils/misc
	${INSTALL_DATA} ${WRKSRC}/src/utils/misc/*.inc \
		${PREFIX}/share/jpgraph/utils/misc

	${INSTALL_DATA} ${WRKSRC}/src/utils/jpdocgen/README \
		${PREFIX}/share/jpgraph/utils/jpdocgen
	${INSTALL_SCRIPT} ${WRKSRC}/src/utils/jpdocgen/*.php \
		${PREFIX}/share/jpgraph/utils/jpdocgen
	${INSTALL_DATA} ${WRKSRC}/src/utils/jpdocgen/*.css \
		${PREFIX}/share/jpgraph/utils/jpdocgen

.include "../../mk/bsd.pkg.mk"
