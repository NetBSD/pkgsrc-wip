# $NetBSD: Makefile,v 1.2 2004/12/02 16:39:06 thomasklausner Exp $
#

DISTNAME=		pwlib_1.5.2
PKGNAME=		pwlib-1.5.2
CATEGORIES=             devel
MASTER_SITES=           http://www.openh323.org/bin/

MAINTAINER=             psham@cs.nmsu.edu
HOMEPAGE=               http://www.openh323.org/
COMMENT=                Multi-platform class library

BUILD_DEPENDS=          bison-[0-9]*:../../devel/bison

WRKSRC=                 ${WRKDIR}/pwlib
USE_BUILDLINK3=         yes
USE_PKGINSTALL=         yes
USE_LIBTOOL=            yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

PTHREAD_OPTS+=          require

MAKE_ENV+=              PWLIBDIR="${WRKSRC}"
MAKE_ENV+=              CC="${CC}"
MAKE_ENV+=              CPLUS="${CXX}"
BUILD_TARGET=             opt

FILES_SUBST+=           LIBTOOL="${LIBTOOL}"
FILES_SUBST+=           PTHREADS_PREFIX="${BUILDLINK_PREFIX.pthread}"

post-patch:
	${_PKG_SILENT}cd ${WRKSRC}/make;                                \
	for f in unix.mak lib.mak common.mak; do                        \
		${SED} ${FILES_SUBST_SED} $$f > $$f.sed;                \
		${MV} -f $$f.sed $$f;                                           \
	done
	${LN} -sf ${WRKDIR} ${WRKSRC}/share

do-install:
	${_PKG_SILENT}cd ${WRKSRC}/src/ptlib/unix && ${MAKE_ENV} ${GMAKE} ${INSTALL}
	${_PKG_SILENT}cd ${WRKSRC}/tools/asnparser && ${MAKE_ENV} ${GMAKE} ${INSTALL}
	${INSTALL_DATA_DIR} ${PREFIX}/include/ptclib
	${INSTALL_DATA_DIR} ${PREFIX}/include/ptlib/unix/ptlib
	cd ${WRKSRC}/include;                                           \
	for f in `${FIND} . -type f -print | ${GREP} -v '/CVS/'`; do    \
		${INSTALL_DATA} $$f ${PREFIX}/include/`${DIRNAME} $$f`; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/pwlib/make
	cd ${WRKSRC}/make;                                              \
	for f in *.mak; do              \
		${INSTALL_DATA} $$f ${PREFIX}/share/pwlib/make;         \
	done
	${CP} -rf ${WRKSRC}/make/ptlib-config ${PREFIX}/bin

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
