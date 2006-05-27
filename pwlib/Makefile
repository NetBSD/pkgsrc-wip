# $NetBSD: Makefile,v 1.1.1.1 2006/05/27 14:10:50 roelants Exp $

DISTNAME=	pwlib-v1_10_0-src
PKGNAME=	pwlib-1.10.0
CATEGORIES=	devel
MASTER_SITES+=	http://www.voxgratia.org/releases/
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/openh323/
COMMENT=	Portable Windows Libary

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

WRKSRC=			${WRKDIR}/${DISTNAME:S/-src$//:S/-/_/}
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-sasl
CONFIGURE_ARGS+=	--disable-expat --disable-qos
PTHREAD_OPTS+=		require

BUILD_TARGET=		opt
MAKE_ENV+=		PWLIBDIR=${WRKSRC:Q} CC=${CC:Q} CPLUS=${CXX:Q}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	make/unix.mak make/lib.mak make/common.mak make/pwlib.mak
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@LIBTOOL@,${LIBTOOL},g'
SUBST_SED.paths+=	-e 's,@BSD_INSTALL_LIB@,${INSTALL_LIB},g'
SUBST_SED.paths+=	-e 's,@BSD_INSTALL_PROGRAM@,${INSTALL_PROGRAM},g'
SUBST_SED.paths+=	-e 's,@PTHREAD_FLAGS@,${PTHREAD_LDFLAGS} ${PTHREAD_LIBS},g'
SUBST_SED.paths+=	-e 's,@LIBOSSAUDIO@,${LIBOSSAUDIO},g'
SUBST_STAGE.paths=	post-patch

do-install:
	cd ${WRKSRC}/src/ptlib/unix && ${MAKE_ENV} ${GMAKE} install
	${INSTALL_DATA_DIR} ${PREFIX}/share/pwlib/make
	${INSTALL_DATA_DIR} ${PREFIX}/include/ptclib
	${INSTALL_DATA_DIR} ${PREFIX}/include/ptlib/unix/ptlib
	cd ${WRKSRC}/make; ${INSTALL_SCRIPT} ptlib-config ${PREFIX}/bin; \
	for f in *.mak; do		\
		${INSTALL_DATA} $$f ${PREFIX}/share/pwlib/make; \
	done
	${INSTALL_DATA} ${WRKSRC}/version.h ${PREFIX}/include/ptlib
	cd ${WRKSRC}; \
	for f in `${FIND} include -name CVS -prune -o -name \\*.orig -prune -o -name wince -prune -o -name msos -prune -o -type f -print`; do	\
		${INSTALL_DATA} $$f ${PREFIX}/$$f;	\
	done

.include "../../databases/openldap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
