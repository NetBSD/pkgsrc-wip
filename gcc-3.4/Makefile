# $NetBSD: Makefile,v 1.12 2004/05/01 20:30:30 johnrshannon Exp $
#

DISTNAME=	gcc-${GCC_VERSION}
CATEGORIES=	lang
MASTER_SITES=   ${MASTER_SITE_GNU:=gcc/gcc-${GCC_VERSION}/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	john@johnrshannon.com
HOMEPAGE=	http://www.gnu.org/software/gcc/gcc.html
COMMENT=	This is the gcc 3.4 compiler

GCC_VERSION=	3.4.0

.include "../../mk/bsd.prefs.mk"

# Optional languages
BUILD_ADA=	YES
BUILD_CXX=	YES
BUILD_F77=	NO
BUILD_JAVA=	NO
BUILD_OBJC=	NO

# Java can't be built on x86_64
.if ${MACHINE_GNU_ARCH} == "x86_64"
java=	NO
.endif

LANGS='c'
.if ${BUILD_ADA} == "YES"
LANGS+='ada'
.endif
.if ${BUILD_CXX} == "YES"
LANGS+='c++'
.endif
.if ${BUILD_F77} == "YES"
LANGS+='f77'
.endif
.if ${BUILD_JAVA} == "YES"
LANGS+='java'
.endif
.if ${BUILD_OBJC} == "YES"
LANGS+='objc'
.endif
CONFIGURE_ARGS+=        --enable-languages="${LANGS}"

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_GNU_TOOLS+=		make
HAS_CONFIGURE=		YES
PTHREAD_OPTS+=  require native
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

.if ${BUILD_ADA} == "YES"
# An Ada compiler is required to build the Ada compiler. Two
may be used:
#USE_GCC3	=# Define to use lang/gcc3-ada
USE_GCC34ADA	=# Define to use gcc-3.4-ada
# You may also specify the path of a gcc/gnat Ada compiler
# outside of the pkgsrc system by specifying the full path
# of the compiler (example) below:
#ALT_GCC=       /usr/pkg/gccAda-3.4.0/bin/gcc
.if defined(ALT_GCC)
ALT_GCC_PREFIX:=        ${ALT_GCC:H}/..
ALT_GCC_RTS!=   ${FIND} ${ALT_GCC_PREFIX} -name adalib
RALT_GCC_RTS=   ${ALT_GCC_RTS:S%${LOCALBASE}%%:S%/%%}
.endif
.endif


GCC_SUBPREFIX=		${PKGNAME_NOREV}
GCC_PREFIX=		${PREFIX}/${GCC_SUBPREFIX}
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

.if ${BUILD_ADA} == "YES"
.if defined(USE_GCC34ADA)
# Overide compiler.mk setup to use gccAda-3.4.0
pre-configure:
.include "../../wip/gcc-3.4-ada/preconfigure.mk"
.elif defined(ALT_GCC)
pre-configure:
	(cd ${WRKDIR}/.buildlink && ${MKDIR} ${RALT_GCC_RTS} && \
	cd ${RALT_GCC_RTS} && ${LN} -s ${ALT_GCC_RTS}/libgnat.a .)
	(cd ${ALT_GCC:H} && \
	bin_files=`${FIND} . -type f \( -perm -0100 \)` && \
	cd ${WRKDIR}/.gcc/bin/ && \
	for file in ${ALT_GCC:T} $${bin_files} ; do \
	  $(ECHO) '#!/bin/sh' > $${file}; \
	  $(ECHO) -n "exec ${ALT_GCC:H}/$${file} " >>$${file}; \
	  $(ECHO) '"$$@"' >>$${file}; \
	  $(CHMOD) +x $${file}; \
	done )
.endif
.endif

do-configure:
	((${TEST} -d  ${WRKDIR}/obj || ${MKDIR} ${WRKDIR}/obj) && \
	 (cd ${WRKDIR}/obj && ${SETENV} ${CONFIGURE_ENV} ${WRKSRC}/configure ${CONFIGURE_ARGS}))

do-build:
.if ${BUILD_ADA} == "YES"
	(cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} bootstrap && cd gcc && ${GMAKE} gnatlib_and_tools)
.else
	(cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} bootstrap)
.endif

do-test:
.if (${MACHINE_GNU_ARCH} == "x86_64")
	(cd files && cp netbsd64macro.dfs ${WRKSRC}/gcc/testsuite/ada/acats/support/macro.dfs)
.endif
	(cd ${WRKDIR}/obj && ${GMAKE} -k check)

do-install:
	(cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} ${INSTALL} \
	 && ${TEST} -f ${GCC_PREFIX}/bin/cc || ${LN} -f ${GCC_PREFIX}/bin/gcc ${GCC_PREFIX}/bin/cc)

post-install:
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
.elif  defined(USE_GCC34ADA)
BUILDLINK_DEPMETHOD.gccAda-3.4.0=build
.include "../../wip/gcc-3.4-ada/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
