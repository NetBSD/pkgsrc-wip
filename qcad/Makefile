# $NetBSD: Makefile,v 1.1 2005/03/08 15:42:53 jcflack Exp $
#

DISTNAME=		qcad-2.0.4.0-1.src
# what to do about this numbering? RibbonSoft really seems to use four digits
# (there's a 2.0.4.7 for some platforms), though I don't know about the
# thing after the hyphen, which always seems to be 1. Can I use four digits?
PKGNAME=		qcad-2.0.4.0

.include "./Makefile.common"

COMMENT=		2D CAD system

USE_BUILDLINK3=		yes
USE_X11=		# defined
GNU_CONFIGURE=		# defined
USE_GNU_TOOLS+= 	make

ED?=			ed

CONFIGURE_DIRS= 	${WRKSRC}/fparser ${WRKSRC}/dxflib

BUILD_DIRS=		${CONFIGURE_DIRS}
.for _sfx_ in lib cmd actions guiqt
  BUILD_DIRS+=		${WRKSRC}/qcad${_sfx_}
.endfor
BUILD_DIRS+=		${WRKSRC}/qcad

# XXX how to determine the below dynamically?
MAKE_ENV+=		QMAKESPEC=${QTDIR}/mkspecs/netbsd-g++
PREPEND_PATH+=		${QTDIR}/bin

# I really want this to be post-*patch* where it makes sense, but QTDIR
# isn't available until PHASES_AFTER_WRAPPER because it depends on
# BUILDLINK_PREFIX.qt3-libs, which buildlink3 sets.  Nothing is easy.  :)
# The patches have replaced old hardcoded paths with fixed cookies @PREFIX@
# and @QTDIR@.  Here a single ed process will expand the cookies in all
# affected files in place.
post-wrapper:
	for f in qcadlib/src/engine/rs_system.cpp \
		 qcad/src/qc_applicationwindow.cpp ; do \
		${ECHO} "e ${WRKSRC}/$$f" ; \
		${ECHO} ",g:@PREFIX@:s:@PREFIX@:${PREFIX}:g" ; \
		${ECHO} ",g:@QTDIR@:s:@QTDIR@:${QTDIR}:g" ; \
		${ECHO} w ; \
	done | ${ED}

# Just setting BUILD_DIRS would be adequate if qcad could be built with
# "prepare all" in each module, one by one.  But qcad needs all modules to
# be prepare'd before any can be all'd, so prepare them here in a separate
# loop duplicated from do-build.  The unmodified do-build then takes care
# of the "all".  I didn't see an easier way.
pre-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}for DIR in ${BUILD_DIRS} ; do \
		( cd $${DIR} &&  \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		-f ${MAKEFILE} prepare ) || exit 1 ; done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcad/qcad ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/qcad
	cd ${WRKSRC}/qcad && umask 022 && \
	${PAX} -rwpm examples fonts patterns qm ${PREFIX}/share/qcad

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
