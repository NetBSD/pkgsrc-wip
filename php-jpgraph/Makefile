# $NetBSD: Makefile,v 1.2 2003/07/08 10:33:40 adrian_p Exp $

DISTNAME=	jpgraph-1.12.2
PKGNAME=	php-${DISTNAME}
CATEGORIES=	graphics www
MASTER_SITES=	http://www.aditus.nu/jpgraph/downloads/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.aditus.nu/jpgraph/index.php
COMMENT=	JpGraph is an OO class library for PHP

DEPENDS+=	php-gd>=4.1:../../graphics/php4-gd

NO_BUILD=	YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/php-jpgraph
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/php-jpgraph
	${INSTALL_DATA_DIR} ${PREFIX}/share/php-jpgraph
	${INSTALL_DATA_DIR} ${PREFIX}/share/php-jpgraph/utils
	${INSTALL_DATA_DIR} ${PREFIX}/share/php-jpgraph/utils/misc
	${INSTALL_DATA_DIR} ${PREFIX}/share/php-jpgraph/utils/jpdocgen

	${INSTALL_SCRIPT} ${WRKSRC}/src/Examples/*.php \
		${PREFIX}/share/examples/php-jpgraph
	${INSTALL_DATA} ${WRKSRC}/src/Examples/*.png \
		${PREFIX}/share/examples/php-jpgraph
	${INSTALL_DATA} ${WRKSRC}/src/Examples/*.gif \
		${PREFIX}/share/examples/php-jpgraph
	${INSTALL_DATA} ${WRKSRC}/src/Examples/*.jpg \
		${PREFIX}/share/examples/php-jpgraph

	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/php-jpgraph
	${INSTALL_DATA} ${WRKSRC}/src/Changelog ${PREFIX}/share/doc/php-jpgraph

	${INSTALL_SCRIPT} ${WRKSRC}/src/*.php ${PREFIX}/share/php-jpgraph
	${INSTALL_DATA} ${WRKSRC}/src/*.inc ${PREFIX}/share/php-jpgraph

	${INSTALL_DATA} ${WRKSRC}/src/utils/Readme \
		${PREFIX}/share/php-jpgraph/utils
	${INSTALL_SCRIPT} ${WRKSRC}/src/utils/misc/*.php \
		${PREFIX}/share/php-jpgraph/utils/misc
	${INSTALL_DATA} ${WRKSRC}/src/utils/misc/*.inc \
		${PREFIX}/share/php-jpgraph/utils/misc

	${INSTALL_DATA} ${WRKSRC}/src/utils/jpdocgen/README \
		${PREFIX}/share/php-jpgraph/utils/jpdocgen
	${INSTALL_SCRIPT} ${WRKSRC}/src/utils/jpdocgen/*.php \
		${PREFIX}/share/php-jpgraph/utils/jpdocgen
	${INSTALL_DATA} ${WRKSRC}/src/utils/jpdocgen/*.css \
		${PREFIX}/share/php-jpgraph/utils/jpdocgen

	cd ${WRKSRC}/docs && ${PAX} -rw . ${PREFIX}/share/doc/php-jpgraph

.include "../../mk/bsd.pkg.mk"
