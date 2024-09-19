# $NetBSD: Makefile,v 1.7 2012/09/29 00:50:40 asau Exp $
#

DISTNAME=	gstat-2.4.3
PKGREVISION=	2
CATEGORIES=	geography math
MASTER_SITES=	http://www.gstat.org/bin/

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.gstat.org/
COMMENT=	Geostatistical modelling, prediction and simulation


GNU_CONFIGURE=	YES
MAKE_FILE=	makefile

# TODO:  detects ncurses instead of curses
CONFIGURE_ARGS+=	--without-curses
# TODO:  does not detect gd properly; needs INCLUDES set properly
CONFIGURE_ARGS+=	--with-gd=no
# TODO:  needs hardcoded paths set properly
#CONFIGURE_ENV+=	INCLUDES=-I${PREFIX}/include

# TODO:  install documentation/examples/etc.
DOCDIR=		${PREFIX}/share/doc/html/gstat

post-extract:
	${MV} ${WRKSRC}/doc/www/makefile ${WRKSRC}/doc/www/makefile.in

post-configure:
	${SED} < ${WRKSRC}/doc/www/makefile.in > ${WRKSRC}/doc/www/makefile \
		-e 's:@DOCDIR@:${DOCDIR}:'

x-post-build:
	cd ${WRKSRC}/doc/www && ${MAKE} -f ${MAKE_FILE} ${BUILD_TARGET}

x-post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/doc/www && ${MAKE} -f ${MAKE_FILE} ${INSTALL_TARGET}

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
