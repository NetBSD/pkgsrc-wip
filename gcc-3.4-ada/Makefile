# $NetBSD: Makefile,v 1.27 2004/04/21 10:01:01 johnrshannon Exp $
#

DISTNAME=	gcc-${GCC_VERSION}-ada
PKGNAME=	gccAda-${GCC_VERSION}
CATEGORIES=	lang
MASTER_SITES=   ${MASTER_SITE_GNU:=gcc/releases/gcc-${GCC_VERSION}/}
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

# An Ada compiler is required to build this pkg. Two
may be used:
#USE_GCC3	=# Define to use lang/gcc3-ada
USE_GCC34	=# Define to use gcc-3.4-ada

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
# Overide compiler.mk setup to use gcc-3.4.0
pre-configure:
	(cd ${BUILDLINK_PREFIX.gcc-3.4.0}/bin && files=`ls gnat*` && \
	cd ${GCC_DIR}/bin/ && \
	for file in gcc cc cpp $${files} ; do \
	  $(ECHO) '#!/bin/sh' > $${file}; \
	  $(ECHO) -n "exec ${BUILDLINK_PREFIX.gcc-3.4.0}/bin/$${file} " >>$${file}; \
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

.include "../../mk/bsd.prefs.mk"
.if defined(USE_GCC3)
.include "../../lang/gcc3-ada/buildlink3.mk"
.elif defined(USE_GCC34)
BUILDLINK_DEPMETHOD.gcc-3.4.0= build
.include "../../wip/gcc-3.4/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
