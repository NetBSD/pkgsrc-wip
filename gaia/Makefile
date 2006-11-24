# $NetBSD: Makefile,v 1.1.1.1 2006/11/24 19:22:39 bartoszkuzma Exp $
#

DISTNAME=		gaia-0.1.0
CATEGORIES=		net
MASTER_SITES=		http://gaia.serezhkin.com/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://gaia.serezhkin.com/
COMMENT=		Opensource 3D interface to the planet

NO_CONFIGURE=		yes
USE_LANGUAGES+=		c++

BUILD_DEPENDS+=		scons>=0.96:../../devel/scons

SCONS_BIN=		${PREFIX}/bin/scons
SCONS_ARGS=		gpsd=0

DATADIR=		${PREFIX}/share/gaia/data
CXXFLAGS+=		-DDATADIR='"${DATADIR}"'

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${SCONS_BIN} -Q ${SCONS_ARGS}

do-install:
	${INSTALL_DATA_DIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/font.png ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gaia ${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
