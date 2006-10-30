# $NetBSD: Makefile,v 1.1.1.1 2006/10/30 11:31:34 hugor Exp $
#
DISTNAME=	geant4.8.1.p01
PKGNAME=	geant-4.8.1p01
CATEGORIES=	math
MASTER_SITES=	http://geant4.web.cern.ch/geant4/support/source/


MAINTAINER=	hugor@users.sourceforge.net
HOMEPAGE=	http://geant4.web.cern.ch/geant4/
COMMENT=	Toolkit for the simulation of the passage of particles through matter

WRKSRC=		${WRKDIR}/${DISTNAME}/source
MAKE_FILE=	GNUmakefile
USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++

BUILD_TARGET=	# empty

# Enviroment variables for building geant4

G4SYSTEM=	Linux-g++
MAKE_ENV+=	G4SYSTEM=Linux-g++
MAKE_ENV+=	G4INSTALL=${WRKDIR}/${DISTNAME}
MAKE_ENV+=	CLHEP_BASE_DIR=${LOCALBASE}
MAKE_ENV+=	G4LIB_BUILD_STATIC=1
MAKE_ENV+=	G4LIB_USE_GRANULAR=1

# Adding OpenGL support

MAKE_ENV+=	G4VIS_USE_OPENGLX=1
MAKE_ENV+=	G4VIS_BUILD_OPENGLX_DRIVER=1
MAKE_ENV+=	OGLHOME=${LOCALBASE}
MAKE_ENV+=	OGLFLAGS="-I${LOCALBASE}/include"
MAKE_ENV+=	OGLLIBS="-L${LOCALBASE}/lib -lGLU -lGL"

# RayTracerX Visualization driver
MAKE_ENV+=	G4VIS_USE_RAYTRACERX=1
MAKE_ENV+=	G4VIS_BUILD_RAYTRACERX_DRIVER=1

# User Interface
MAKE_ENV+=	G4UI_USE_TERMINAL=1

do-install:
	${INSTALL_DATA_DIR} ${LOCALBASE}/geant
	${INSTALL_DATA_DIR} ${LOCALBASE}/geant/config
	${INSTALL_DATA_DIR} ${LOCALBASE}/geant/examples
	${INSTALL_DATA_DIR} ${LOCALBASE}/geant/lib
	${INSTALL_LIB_DIR} ${LOCALBASE}/geant/lib/${G4SYSTEM}
	${INSTALL_DATA_DIR} ${LOCALBASE}/geant/physics_lists
	${INSTALL_DATA_DIR} ${LOCALBASE}/geant/source
	cd ${WRKDIR}/${DISTNAME}/config && pax -pp -rw . \
		${LOCALBASE}/geant/config
	cd ${WRKDIR}/${DISTNAME}/examples && pax -pp -rw . \
		${LOCALBASE}/geant/examples
	${INSTALL_LIB} ${WRKDIR}/${DISTNAME}/lib/${G4SYSTEM}/* \
		${LOCALBASE}/geant/lib/${G4SYSTEM}
	cd ${WRKDIR}/${DISTNAME}/physics_lists && pax -pp -rw . \
		${LOCALBASE}/geant/physics_lists
	cd ${WRKDIR}/${DISTNAME}/source && pax -pp -rw . \
		${LOCALBASE}/geant/source


.include	"../../wip/clhep/buildlink3.mk"
.include	"../../graphics/MesaLib/buildlink3.mk"
.include	"../../graphics/glu/buildlink3.mk"
.include	"../../mk/x11.buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
