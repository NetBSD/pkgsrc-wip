# $NetBSD: Makefile,v 1.6 2004/04/30 10:56:36 johnrshannon Exp $
#

DISTNAME=	gcc-${GCC_VERSION}
CATEGORIES=	lang
MASTER_SITES=   ${MASTER_SITE_GNU:=gcc/gcc-${GCC_VERSION}/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	john@johnrshannon.com
HOMEPAGE=	http://www.gnu.org/software/gcc/gcc.html
COMMENT=	This is the gcc 3.4 compiler

GCC_VERSION=	3.4.0

INSTLIBS=	libsupc++.la
INSTLIBS=	libstdc++.la
INSTLIBS=	libg2c.la
INSTLIBS=	libobjc.la
INSTLIBS=	libffi.la
INSTLIBS=	libgcj.la
INSTLIBS=	lib-org-xml-sax.la
INSTLIBS=	lib-org-w3c-dom.la

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_GNU_TOOLS+=		make
HAS_CONFIGURE=		YES
PTHREAD_OPTS+=  require native
.if (${MACHINE_GNU_ARCH} == "x86_64")
CONFIGURE_ARGS+=        --enable-languages="c,ada,c++,f77,objc"
.else
CONFIGURE_ARGS+=        --enable-languages="c,ada,c++,f77,objc,java"
.endif
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

# An Ada compiler is required to build this pkg. Two
may be used:
#USE_GCC3	=# Define to use lang/gcc3-ada
USE_GCC34ADA	=# Define to use gcc-3.4-ada

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

.if defined(USE_GCC34ADA)
# Overide compiler.mk setup to use gccAda-3.4.0
pre-configure:
.include "../../wip/gcc-3.4-ada/preconfigure.mk"
.endif

do-configure:
	((${TEST} -d  ${WRKDIR}/obj || ${MKDIR} ${WRKDIR}/obj) && \
	 (cd ${WRKDIR}/obj && ${SETENV} ${CONFIGURE_ENV} ${WRKSRC}/configure ${CONFIGURE_ARGS}))

do-build:
	(cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} bootstrap && cd gcc && ${GMAKE} gnatlib_and_tools)

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
