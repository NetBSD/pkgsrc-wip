# $NetBSD: Makefile,v 1.30 2004/04/25 07:43:35 johnrshannon Exp $
#

DISTNAME=	gcc-${GCC_VERSION}-ada
PKGNAME=	gccAda-${GCC_VERSION}
CATEGORIES=	lang
MASTER_SITES=   ${MASTER_SITE_GNU:=gcc/gcc-${GCC_VERSION}/}
DISTFILES=	gcc-${GCC_VERSION}.tar.bz2

MAINTAINER=	john@johnrshannon.com
HOMEPAGE=	http://www.gnu.org/software/gcc/gcc.html
COMMENT=	This is the gcc 3.4 Ada compiler

GCC_VERSION=	3.4.0

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_GNU_TOOLS+=		make
HAS_CONFIGURE=		YES
PTHREAD_OPTS+=  require native
CONFIGURE_ARGS+=        --enable-languages="c,ada"
WRKSRC=		${WRKDIR}/gcc-${GCC_VERSION}
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

# An Ada compiler is required to build this pkg. Two
may be used:
#USE_GCC3	=# Define to use lang/gcc3-ada
USE_GCC34	=# Define to use gcc-3.4
# You may also specify the path of a gcc/gnat Ada compiler
# outside of the pkgsrc system by specifying the full path
# of the compiler (example) below:
#ALT_GCC=	/usr/pkg/gcc3bootstrap/bin/gcc
.if defined(ALT_GCC)
ALT_GCC_PREFIX:=	${ALT_GCC:H}/..
ALT_GCC_RTS!=	find ${ALT_GCC_PREFIX} -name adalib
RALT_GCC_RTS=	${ALT_GCC_RTS:S%${LOCALBASE}%%:S%/%%}
.endif

# Make location overridable, to allow ping-pong bootstraps.
GCC34_DEFAULT_SUBPREFIX=	${PKGNAME_NOREV}
GCC34_INSTALLTO_SUBPREFIX?=	${GCC34_DEFAULT_SUBPREFIX}
.if ${GCC34_INSTALLTO_SUBPREFIX} != ${GCC34_DEFAULT_SUBPREFIX}
GCC34_PKGMODIF=		_${GCC34_INSTALLTO_SUBPREFIX}
.endif

GCC_SUBPREFIX=		${GCC34_INSTALLTO_SUBPREFIX}
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
GCC_DIR=	${WRKDIR}/.gcc

post-patch:
	(cd files; \
	${CP} adasignal.c ${WRKSRC}/gcc/ada; \
	${CP} ada_lwp_self.c ${WRKSRC}/gcc/ada; \
	${CP} dummy_pthreads.c ${WRKSRC}/gcc/ada; \
	for i in *.adb *.ads ; do \
		${CP} $$i ${WRKSRC}/gcc/ada; \
	done )

.if defined(USE_GCC34)
pre-configure:
.include "../../wip/gcc-3.4/preconfigure.mk"
.elif defined(ALT_GCC)
pre-configure:
	(cd ${WRKDIR}/.buildlink && ${MKDIR} ${RALT_GCC_RTS} && \
	cd ${RALT_GCC_RTS} && ln -s ${ALT_GCC_RTS}/libgnat.a .) 
	(cd ${ALT_GCC:H} && \
	files=`${FIND} . -type f \( -perm -0100 \)` && \
	cd ${GCC_DIR}/bin/ && \
	for file in ${ALT_GCC:T} $${files} ; do \
	  $(ECHO) '#!/bin/sh' > $${file}; \
	  $(ECHO) -n "exec ${ALT_GCC:H}/$${file} " >>$${file}; \
	  $(ECHO) '"$$@"' >>$${file}; \
	  $(CHMOD) +x $${file}; \
	done )
.endif

do-configure:
	((${TEST} -d  ${WRKDIR}/obj || ${MKDIR} ${WRKDIR}/obj) && \
	 (cd ${WRKDIR}/obj && ${SETENV} ${CONFIGURE_ENV} ${WRKSRC}/configure ${CONFIGURE_ARGS}))

do-build:
	(cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} bootstrap && cd gcc && ${GMAKE} gnatlib_and_tools)

do-test:
	(cd ${WRKDIR}/obj && ${GMAKE} -k check)

do-install:
	(cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} install \
	 && ${TEST} -f ${GCC_PREFIX}/bin/cc || ${LN} -f ${GCC_PREFIX}/bin/gcc ${GCC_PREFIX}/bin/cc)

post-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/ada > ${WRKDIR}/ada
	${ECHO} '"$$@"' >> ${WRKDIR}/ada
	${INSTALL_DATA} ${WRKDIR}/ada ${LOCALBASE}/bin/ada
	${CHMOD} +x ${WRKDIR}/ada ${LOCALBASE}/bin/ada
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} \( -type f -o -type l \) -print	\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"	\
		>> ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} -type d -print	\
		| ${SORT} -r | ${SED} -e "s,${PREFIX}/,@dirrm ,g"	\
		>> ${PLIST_SRC}


.include "../../mk/bsd.prefs.mk"
.if defined(USE_GCC3)
.include "../../lang/gcc3-ada/buildlink3.mk"
.elif defined(USE_GCC34)
BUILDLINK_DEPMETHOD.gcc-3.4.0=	build
.include "../../wip/gcc-3.4/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
