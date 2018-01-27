# $NetBSD: Makefile,v 1.2 2012/10/04 19:44:06 asau Exp $
#

DISTNAME=	palp-1.1
CATEGORIES=	math
MASTER_SITES=	http://hep.itp.tuwien.ac.at/%7Ekreuzer/CY/palp/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://hep.itp.tuwien.ac.at/%7Ekreuzer/CY/palp/
COMMENT=	Analyzing lattice polytopes
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/palp
MAKE_FILE=	GNUmakefile

INSTALLATION_DIRS+=	bin share/doc/palp

post-extract:
	${CP} ${FILESDIR}/palp.pdf ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/class.x \
		${DESTDIR}${PREFIX}/bin
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/class.x
	${INSTALL_DATA} ${WRKSRC}/cws.x \
		${DESTDIR}${PREFIX}/bin
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/cws.x
	${INSTALL_DATA} ${WRKSRC}/nef.x \
		${DESTDIR}${PREFIX}/bin
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/nef.x
	${INSTALL_DATA} ${WRKSRC}/poly.x \
		${DESTDIR}${PREFIX}/bin
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/poly.x
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/palp
	${INSTALL_DATA} ${FILESDIR}/palp.pdf \
		${DESTDIR}${PREFIX}/share/doc/palp

.include "../../mk/bsd.pkg.mk"
