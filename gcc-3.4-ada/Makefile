# $NetBSD: Makefile,v 1.2 2004/01/08 13:34:42 johnrshannon Exp $
#

SNAPDATE=	20040107
GCC_VERSION=	3.4
DISTNAME=	gcc-${GCC_VERSION}-ada
WRKSRC=		${WRKDIR}/gcc-${GCC_VERSION}-${SNAPDATE}
CATEGORIES=	lang
MASTER_SITES=	ftp://gcc.gnu.org/pub/gcc/snapshots/${GCC_VERSION}-${SNAPDATE}/ \
		ftp://mirrors.rcn.net/pub/sourceware/gcc/snapshots/${GCC_VERSION}-${SNAPDATE}/
DISTFILES=	gcc-${GCC_VERSION}-${SNAPDATE}.tar.bz2

MAINTAINER=	john@johnrshannon.com
HOMEPAGE=	http://www.gnu.org/software/gcc/gcc.html
COMMENT=	This is the developmental gcc 3.4 Ada compiler

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_GMAKE=		YES
HAS_CONFIGURE=		YES
PTHREAD_OPTS+=  require native
CONFIGURE_ARGS+=        --enable-languages="c,ada"
EXTRA_ENV+=     ADAC=/usr/pkg/gcc3/bin/gcc
CONFIGURE_ENV+= ${EXTRA_ENV}
MAKE_ENV+=      ${EXTRA_ENV}

# Make location overridable, to allow ping-pong bootstraps.
GCC3_DEFAULT_SUBPREFIX=	gcc3
GCC3_INSTALLTO_SUBPREFIX?=	${GCC3_DEFAULT_SUBPREFIX}
.if ${GCC3_INSTALLTO_SUBPREFIX} != ${GCC3_DEFAULT_SUBPREFIX}
GCC3_PKGMODIF=		_${GCC3_INSTALLTO_SUBPREFIX}
.endif

GCC_SUBPREFIX=		${GCC3_INSTALLTO_SUBPREFIX}
GCC_PREFIX=		${PREFIX}/${GCC_SUBPREFIX}
PLIST_SUBST+=		GCC_SUBPREFIX=${GCC_SUBPREFIX}
FILES_SUBST+=		GCC_PREFIX=${GCC_PREFIX}
FILES_SUBST+=		PKGNAME=${PKGNAME}
MESSAGE_SUBST+=		GCC_PREFIX=${GCC_PREFIX}
CONFIGURE_ARGS+=	--prefix=${GCC_PREFIX}
GCC_PLATFORM=		${MACHINE_GNU_ARCH}--netbsdelf2.0
PTHREAD_OPTS+=		require native
CPPFLAGS+=	-I${BUILDLINK_DIR}/include
CFLAGS+=	-I${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--host=${GCC_PLATFORM}
GCC_ARCHSUBDIR=	${GCC_SUBPREFIX}/lib/gcc/${GCC_PLATFORM}/${GCC_VERSION}
GCC_ARCHDIR=	${PREFIX}/${GCC_ARCHSUBDIR}

post-patch:
	(cd files; \
		${CP} adasignal.c ${WRKSRC}/gcc/ada; \
		${CP} ada_lwp_self.c ${WRKSRC}/gcc/ada; \
		${CP} dummy_pthreads.c ${WRKSRC}/gcc/ada; \
		for i in *.adb *.ads ; do \
		${CP} $$i ${WRKSRC}/gcc/ada; \
	done )

do-configure:
	(test -d  ${WRKDIR}/obj || mkdir ${WRKDIR}/obj && cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${WRKSRC}/configure ${CONFIGURE_ARGS})

do-build:
	(cd ${WRKDIR}/obj && ${GMAKE} bootstrap && cd gcc && ${GMAKE} gnatlib_and_tools)

do-test:
	(cd ${WRKDIR}/obj && ${GMAKE} -k check)

do-install:
	(cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} install \
	 && test -f ${GCC_PREFIX}/bin/cc || ln -s ${GCC_PREFIX}/bin/gcc ${GCC_PREFIX}/bin/cc \
	 && test -f ${GCC_PREFIX}/bin/gnat1 || ln -s ${GCC_ARCHDIR}/3.4.0/gnat1 ${GCC_PREFIX}/bin/gnat1)

.include "../../mk/bsd.prefs.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
