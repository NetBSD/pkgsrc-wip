# $NetBSD: Makefile,v 1.9 2012/10/14 15:16:58 asau Exp $
#

DISTNAME=	geant4.9.5
PKGNAME=	geant-4.9.5
CATEGORIES=	math
MASTER_SITES=	http://geant4.web.cern.ch/geant4/support/source/


MAINTAINER=	hugor@users.sourceforge.net
HOMEPAGE=	http://geant4.web.cern.ch/geant4/
COMMENT=	Toolkit for the simulation of the passage of particles through matter

CONFIGURE_DIRS=	source
USE_TOOLS+=	gmake pax perl:run
USE_LANGUAGES=	c c++
MAKE_FILE=	GNUmakefile
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

# Override "echo -e" gnuism
MAKE_FLAGS+=	ECHO=echo

# It should be:
#REPLACE_CSH=		examples/extended/biasing/B02/setupPI.csh
# skip it for now:
CHECK_INTERPRETER_SKIP=	geant/examples/extended/biasing/B02/setupPI.csh \
			geant/examples/extended/medical/electronScattering2/run.csh

REPLACE_PERL=	examples/advanced/ChargeExchangeMC/util/mkacchist \
		examples/advanced/ChargeExchangeMC/util/mkjob
REPLACE_PYTHON=	examples/extended/eventgenerator/exgps/macros/plotall.py \
		examples/extended/eventgenerator/exgps/macros/plotfiles.py \
		examples/extended/eventgenerator/exgps/macros/plottest35.py

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
	cd ${WRKDIR}/${DISTNAME}/source && pax -pp -rw . \
		${DESTDIR}${PREFIX}/geant/source

.include "../../lang/python/application.mk"
.include "../../wip/clhep/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
