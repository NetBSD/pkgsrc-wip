# $NetBSD: Makefile,v 1.5 2004/01/11 14:33:04 johnrshannon Exp $
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
ADA_BOOT_PATH=               /usr/pkg/gcc3.4
ADA_BOOT_ADAC?=  ${ADA_BOOT_PATH}/bin/gcc
ADA_BOOT_GNATBIND=      ${ADA_BOOT_PATH}/bin/gnatbind
EXTRA_ENV+=     ADAC=${ADA_BOOT_ADAC:Q}
CONFIGURE_ENV+=	${EXTRA_ENV}
MAKE_ENV+=	${EXTRA_ENV}

# Make location overridable, to allow ping-pong bootstraps.
GCC3_DEFAULT_SUBPREFIX=	gcc3.4
GCC3_INSTALLTO_SUBPREFIX?=	${GCC3_DEFAULT_SUBPREFIX}
.if ${GCC3_INSTALLTO_SUBPREFIX} != ${GCC3_DEFAULT_SUBPREFIX}
GCC3_PKGMODIF=		_${GCC3_INSTALLTO_SUBPREFIX}
.endif

GCC_SUBPREFIX=		${GCC3_INSTALLTO_SUBPREFIX}
GCC_PREFIX=		${PREFIX}/${GCC_SUBPREFIX}
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
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

#post-buildlink:
#	${LN} -sf ${ADA_BOOT_GNATBIND} ${BUILDLINK_DIR}/bin

do-configure:
	(${TEST} -d  ${WRKDIR}/obj || ${MKDIR} ${WRKDIR}/obj && cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${WRKSRC}/configure ${CONFIGURE_ARGS})

do-build:
	(cd ${WRKDIR}/obj && ${GMAKE} bootstrap && cd gcc && ${GMAKE} gnatlib_and_tools)

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/gcc3.mk > ${WRKDIR}/gcc3.mk

do-test:
	(cd ${WRKDIR}/obj && ${GMAKE} -k check)

do-install:
	(cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} install \
	 && ${TEST} -f ${GCC_PREFIX}/bin/cc || ${LN} -f ${GCC_PREFIX}/bin/gcc ${GCC_PREFIX}/bin/cc)

post-install:
	${ECHO} -n 'GCC_EXEC_PREFIX='>> ${WRKDIR}/gcc3.mk
	${DIRNAME} `${GCC_PREFIX}/bin/gcc -print-prog-name=gnat1` >> ${WRKDIR}/gcc3.mk
	${ECHO} -n 'ADA_INCLUDE_PATH+='>> ${WRKDIR}/gcc3.mk
	${FIND} ${GCC_PREFIX} -name adainclude -print >> ${WRKDIR}/gcc3.mk
	${ECHO} -n 'ADA_OBJECTS_PATH+='>> ${WRKDIR}/gcc3.mk
	${FIND} ${GCC_PREFIX} -name adalib -print >> ${WRKDIR}/gcc3.mk
	${INSTALL_DATA_DIR} ${GCC_PREFIX}/mk
	${INSTALL_DATA} ${WRKDIR}/gcc3.mk ${GCC_PREFIX}/mk/ada.mk
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"			\
		>> ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} -type d -print				\
		| ${SORT} -r | ${SED} -e "s,${PREFIX}/,@dirrm ,g"	\
		>> ${PLIST_SRC}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
