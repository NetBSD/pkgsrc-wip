# $NetBSD: Makefile,v 1.3 2006/12/06 13:34:59 bartoszkuzma Exp $
#

DISTNAME=		gaia-0.1.2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gaia-clean/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://gaia.serezhkin.com/
COMMENT=		Opensource 3D interface to the planet

NO_CONFIGURE=		yes
USE_LANGUAGES=		c++

BUILD_DEPENDS+=		scons>=0.96:../../devel/scons

DATADIR=		share/gaia/data

SCONS_BIN=		${PREFIX}/bin/scons
SCONS_ARGS=		gpsd=0
SCONS_ARGS+=		use_env=1
SCONS_ARGS+=		prefix=${PREFIX}
SCONS_ARGS+=		bindir=bin
SCONS_ARGS+=		datadir=${DATADIR}

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV:Q} CCFLAGS=${CFLAGS:Q} \
			${SCONS_BIN} -Q ${SCONS_ARGS}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/font.png ${PREFIX}/${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gaia ${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
