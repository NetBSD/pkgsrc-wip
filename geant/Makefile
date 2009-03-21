# $NetBSD: Makefile,v 1.5 2009/03/21 15:37:13 asau Exp $
#

DISTNAME=	geant4.8.1.p01
PKGNAME=	geant-4.8.1p01
CATEGORIES=	math
MASTER_SITES=	http://geant4.web.cern.ch/geant4/support/source/


MAINTAINER=	hugor@users.sourceforge.net
HOMEPAGE=	http://geant4.web.cern.ch/geant4/
COMMENT=	Toolkit for the simulation of the passage of particles through matter

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}/source
MAKE_FILE=	GNUmakefile
USE_TOOLS+=	gmake pax
USE_LANGUAGES=	c c++

BUILD_TARGET=	# empty

# Enviroment variables for building geant4

G4SYSTEM=	Linux-g++
MAKE_ENV+=	G4SYSTEM=Linux-g++
MAKE_ENV+=	G4INSTALL=${WRKDIR}/${DISTNAME}
MAKE_ENV+=	CLHEP_BASE_DIR=${PREFIX}
MAKE_ENV+=	G4LIB_BUILD_STATIC=1
MAKE_ENV+=	G4LIB_USE_GRANULAR=1

# Adding OpenGL support

MAKE_ENV+=	G4VIS_USE_OPENGLX=1
MAKE_ENV+=	G4VIS_BUILD_OPENGLX_DRIVER=1
MAKE_ENV+=	OGLHOME=${PREFIX}
MAKE_ENV+=	OGLFLAGS="-I${PREFIX}/include"
MAKE_ENV+=	OGLLIBS="-L${PREFIX}/lib -lGLU -lGL"

# RayTracerX Visualization driver
MAKE_ENV+=	G4VIS_USE_RAYTRACERX=1
MAKE_ENV+=	G4VIS_BUILD_RAYTRACERX_DRIVER=1

# User Interface
MAKE_ENV+=	G4UI_USE_TERMINAL=1

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/geant
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/geant/config
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/geant/examples
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/geant/lib
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/geant/lib/${G4SYSTEM}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/geant/physics_lists
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/geant/source
	cd ${WRKDIR}/${DISTNAME}/config && pax -pp -rw . \
		${DESTDIR}${PREFIX}/geant/config
	cd ${WRKDIR}/${DISTNAME}/examples && pax -pp -rw . \
		${DESTDIR}${PREFIX}/geant/examples
	${INSTALL_LIB} ${WRKDIR}/${DISTNAME}/lib/${G4SYSTEM}/* \
		${DESTDIR}${PREFIX}/geant/lib/${G4SYSTEM}
	cd ${WRKDIR}/${DISTNAME}/physics_lists && pax -pp -rw . \
		${DESTDIR}${PREFIX}/geant/physics_lists
	cd ${WRKDIR}/${DISTNAME}/source && pax -pp -rw . \
		${DESTDIR}${PREFIX}/geant/source

.include	"../../wip/clhep/buildlink3.mk"
.include	"../../graphics/MesaLib/buildlink3.mk"
.include	"../../graphics/glu/buildlink3.mk"
.include	"../../x11/libXt/buildlink3.mk"
.include	"../../x11/libXmu/buildlink3.mk"
.include	"../../x11/libX11/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
