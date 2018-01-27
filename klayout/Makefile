# $NetBSD: Makefile,v 1.9 2017/07/11 19:41:20 joerg Exp $

DISTNAME=	klayout-0.25
CATEGORIES=	cad
MASTER_SITES=	http://www.klayout.org/downloads/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.klayout.de/
COMMENT=	Simple GDS and OASIS file viewer and Editor
LICENSE=	gnu-gpl-v2

BROKEN=		Makefile:337: recipe for target 'tlClassRegistry.lo' failed

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake bash

CFLAGS+=	-I${PREFIX}/include/python${PYVERSUFFIX}
NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}

SUBST_CLASSES+=		rpath
SUBST_MESSAGE.rpath=	Add COMPILER_RPATH_FLAG and PREFIX to NetBSD specific config file
SUBST_FILES.rpath+=	config/Makefile.conf.netbsd-32-gcc-release
SUBST_STAGE.rpath=	post-patch
SUBST_VARS.rpath=	COMPILER_RPATH_FLAG PREFIX
SUBST_SED.rpath=	-e 's|@@LDFLAGS@@|${LDFLAGS}|'

AUTO_MKDIRS=		yes
INSTALL_BINDIR=		${DESTDIR}${PREFIX}/bin
INSTALL_LIBDIR=		${DESTDIR}${PREFIX}/lib
REL_DIR=		build.netbsd-32-gcc-release

OTHER_BIN= \
	strm2cif \
	strm2dxf \
	strm2gds \
	strm2gdstxt \
	strm2oas \
	strm2txt \
	strmclip \
	strmcmp \
	strmxor

do-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${BASH} build.sh -python python${PYVERSSUFFIX} \
	-qt4 \
	-qmake ${PREFIX}/qt4/bin/qmake \
	-ruby ${PREFIX}/bin/${RUBY_NAME}

do-install:
	(cd ${WRKSRC}; \
	pwd; \
	${INSTALL_PROGRAM} ${REL_DIR}/main/klayout ${INSTALL_BINDIR}; \
	${INSTALL_LIB} ${REL_DIR}/main/libklayout.so ${INSTALL_LIBDIR} ;\
	for bin in ${OTHER_BIN}; do \
	  ${INSTALL_PROGRAM} ${REL_DIR}/main/$$bin ${INSTALL_BINDIR} ;\
	done ;\
	${CHMOD} 755 ${INSTALL_BINDIR}/* ;\
	)

.include "../../lang/python/pyversion.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
# libQtDesigner
.include "../../x11/qt4-tools/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../mk/bsd.pkg.mk"
