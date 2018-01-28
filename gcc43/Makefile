# $NetBSD: Makefile,v 1.3 2011/11/21 19:08:56 absd Exp $
#

DISTNAME=		gcc-${GCC_VERSION}
PKGNAME=		gcc43-${GCC_VERSION}
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-${GCC_VERSION}/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		blair.sadewitz@gmail.com
HOMEPAGE=		http://gcc.gnu.org/
COMMENT=		This is the GCC 4.3.2 compiler

USE_TOOLS+=		awk:run bash:build perl chmod ar \
			gmake makeinfo msgfmt bison flex gm4

GCC_VERSION=		4.3.2

GCC_SUBPREFIX=		gcc43
GCC_PREFIX=		${DESTDIR}${PREFIX}/${GCC_SUBPREFIX}
FILES_SUBST+=		PKGNAME=${PKGNAME}
MESSAGE_SUBST+=		GCC_PREFIX=${GCC_PREFIX}

# XXX do you really need this? you do it manually
HAS_CONFIGURE=		YES # no GNU_CONFIGURE!
# To avoid GNU surprises
CONFIG_SHELL=		${TOOLS_PATH.bash}
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
# XXX do you really need c++ to compile gcc?
USE_LANGUAGES+=		c c++

NOT_FOR_PLATFORM=	Interix-*-*
UNLIMIT_RESOURCES+=	datasize

.undef PKG_DEVELOPER

.include "../../mk/bsd.prefs.mk"

# Determine whether to use binutils

# REPLACE_AWK+=	gcc/testsuite/gcc.test-framework/test-framework.awk	\
# 		gcc/mkmap-symver.awk					\
# 		gcc/optc-gen.awk					\
# 		gcc/mkmap-flat.awk					\
# 		gcc/opt-gather.awk					\
# 		gcc/opth-gen.awk					\
# 		gcc/opt-functions.awk

# Optional languages - change as required
#
# XXX As of now, only BUILD_CXX BUILD_OBJC and BUILD_FORTRAN are supported
BUILD_DEFS+=		BUILD_CXX BUILD_OBJC BUILD_FORTRAN
BUILD_CXX?=		YES
BUILD_FORTRAN?=		YES
BUILD_OBJC?=		YES

LANGS=	c
.if !empty(BUILD_CXX:M[Yy][Ee][Ss])
LANGS+=	c++
.endif
.if !empty(BUILD_FORTRAN:M[Yy][Ee][Ss])
LANGS+=	fortran
.endif
.if !empty(BUILD_OBJC:M[Yy][Ee][Ss])
LANGS+=	objc
.endif

CONFIGURE_ARGS+=	--prefix=${GCC_PREFIX:Q}
CONFIGURE_ARGS+=	--enable-languages=${LANGS:Q}
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-__cxa_atexit
CONFIGURE_ARGS+=	--enable-long-long
CONFIGURE_ARGS+=	--with-local-prefix=${GCC_PREFIX:Q}
CONFIGURE_ARGS+=	--disable-libssp
CONFIGURE_ARGS+=	--enable-threads=posix # XXX seems to be needed
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
CONFIGURE_ARGS+=	--with-mpfr=${BUILDLINK_PREFIX.mpfr}

CONFIGURE_ENV+=		CONFIG_SHELL=${CONFIG_SHELL}

MAKE_ENV+=		ICONVPREFIX=${BUILDLINK_PREFIX.iconv}
MAKE_ENV+=		SHELL=${CONFIG_SHELL}
MAKE_ENV+=		ac_cv_path_ac_cv_prog_chmod=${TOOLS_CHMOD}

CPPFLAGS+=		-I${BUILDLINK_DIR}/include
CFLAGS+=		-I${BUILDLINK_DIR}/include

# Somone should fix this so it will match the NetBSD system compiler
#.if ${OPSYS} == "NetBSD"
#GCC_PLATFORM=		${LOWER_ARCH}--${LOWER_OPSYS}${APPEND_ELF}
#CONFIGURE_ARGS+=	--host=${GCC_PLATFORM:Q}
#MAKE_ENV+=		AR=/usr/bin/ar
#.endif # NetBSD


do-configure:
	${MKDIR} ${WRKDIR}/obj
	cd ${WRKDIR}/obj; ${SETENV} ${CONFIGURE_ENV} ${CONFIG_SHELL} ${WRKSRC}/configure ${CONFIGURE_ARGS}

do-build:
	(${_ULIMIT_CMD} cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} -j${MAKE_JOBS:U1} )

# do-build:
# 	(${_ULIMIT_CMD} cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} -j${MAKE_JOBS:U1} bootstrap)

do-test:
.if (${MACHINE_GNU_ARCH} == "x86_64")
	(cd ${FILESDIR} && ${CP} netbsd64macro.dfs ${WRKSRC}/gcc/testsuite/ada/acats/support/macro.dfs)
.endif
	(cd ${WRKDIR}/obj && ${GMAKE} -k check)

do-install:
	(cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} install \
	 && ${TEST} -f ${GCC_PREFIX}/bin/cc || ${LN} -f ${GCC_PREFIX}/bin/gcc ${GCC_PREFIX}/bin/cc)

post-install:
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} \( -type f -o -type l \) -print	\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"	\
		>> ${PLIST_SRC}

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
