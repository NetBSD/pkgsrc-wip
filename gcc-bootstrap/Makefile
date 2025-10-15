# $NetBSD: Makefile,v 1.1 2025/07/02 08:30:00 dkazankov Exp $

DISTNAME=	gcc-${PKGVERSION_NOREV}
PKGNAME=	gcc-bootstrap-10.5.0
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/${DISTNAME}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://gcc.gnu.org/
COMMENT=	GCC bootsrap builder (includes GNAT)
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

DISTFILES=	${DEFAULT_DISTFILES}

USE_LANGUAGES=	#empty

USE_TOOLS+=		gmake makeinfo sed tar perl pax bzip2
USE_TOOLS.NetBSD+=	gsed

TOOL_DEPENDS+=		gcc10-aux-[0-9]*:../../lang/gcc10-aux

# Relocations result in a linker error on AArch64, but not x86.
MKPIE_SUPPORTED=	no

CHECK_RELRO_SKIP+=	${PKGBASE}/lib/*

GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no

UNLIMIT_RESOURCES+=	datasize
UNLIMIT_RESOURCES+=	stacksize

CHECK_PORTABILITY_SKIP+=	contrib/*

.include "../../mk/bsd.prefs.mk"

ISL16=			isl-0.16.1
SITES.${ISL16}.tar.bz2=	${MASTER_SITE_GNU:=gcc/infrastructure/}
DISTFILES+=		${ISL16}.tar.bz2

post-extract:
	${MV} ${WRKDIR}/${ISL16} ${WRKSRC}/isl

.if ${OS_VARIANT} == "SmartOS"
SUBST_CLASSES+=		ccs
SUBST_STAGE.ccs=	pre-configure
SUBST_FILES.ccs=	contrib/make_sunver.pl
SUBST_SED.ccs=		-e 's,/usr/ccs/bin,/usr/bin,g'
.endif

# Use C preprocessed symbols on NetBSD (only)
.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		patch1
SUBST_MESSAGE.patch1=	Replace nanosleep, gettimeofday in ${SUBST_FILES.patch1}
SUBST_STAGE.patch1=	pre-configure
SUBST_FILES.patch1=	gcc/ada/libgnat/s-osprim__posix.adb
SUBST_SED.patch1=	-e "s,\"nanosleep\",\"__gnat_nanosleep\","
SUBST_SED.patch1+=	-e "s,\"gettimeofday\",\"__gnat_gettimeofday\","

SUBST_CLASSES+=		patch2
SUBST_MESSAGE.patch2=	Replace select with __gnat_select in ${SUBST_FILES.patch2}
SUBST_STAGE.patch2=	pre-configure
SUBST_FILES.patch2=	gcc/ada/libgnat/g-socthi.ads
SUBST_SED.patch2=	-e "s,\"select\",\"__gnat_select\","

SUBST_CLASSES+=		patch3
SUBST_MESSAGE.patch3=	Replace socket with __gnat_socket in ${SUBST_FILES.patch3}
SUBST_STAGE.patch3=	pre-configure
SUBST_FILES.patch3=	gcc/ada/libgnat/g-socthi__bsd.adb
SUBST_SED.patch3=	-e "s,\"socket\",\"__gnat_socket\","
.endif

## Build outside ${WRKSRC}
OBJDIR=		${WRKDIR}/build

#GARCH=		${MACHINE_ARCH:S/amd64/x86_64/}
#BUILD_TARGET=	${GARCH}-${LOWER_OPSYS}${OS_VERSION}

pre-configure:
	${MKDIR} ${OBJDIR}

CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${PREFIX}/${PKGBASE}

# Disable fixincludes on SmartOS, header changes result in broken includes
# being generated, see https://github.com/joyent/pkgsrc-legacy/issues/270
# Same on QNX.
.if ${OS_VARIANT} == "SmartOS" || ${OPSYS} == "QNX"
SUBST_CLASSES+=		fixinc
SUBST_STAGE.fixinc=	post-extract
SUBST_FILES.fixinc=	gcc/Makefile.in
SUBST_SED.fixinc=	-e "s,\./fixinc.sh,-c true,"
.endif

CONFIGURE_ENV.QNX+=	ACCEPT_INFERIOR_RM_PROGRAM=yes
# Make invokes further configure scripts
MAKE_ENV.QNX+=		ACCEPT_INFERIOR_RM_PROGRAM=yes
MAKE_ENV.QNX+=		GENAUTOMATA_LDFLAGS="-Wl,--stack,10000000"

.if ${MACHINE_PLATFORM:MNetBSD-*-*}
# on NetBSD, use the native SSP code in libc
CONFIGURE_ARGS+=	--disable-libssp
.else
CONFIGURE_ARGS+=	--enable-libssp
.endif

.if ${MACHINE_PLATFORM:MNetBSD-*-*}
# Match base libstdc++ major
SUBST_CLASSES+=		libstdc
SUBST_STAGE.libstdc=	pre-configure
SUBST_FILES.libstdc=	libstdc++-v3/configure
SUBST_MESSAGE.libstdc=	Bumping libstdc++ major to 7
SUBST_SED.libstdc=	-e 's,libtool_VERSION=6:,libtool_VERSION=7:,g'
.endif

CONFIGURE_ARGS+=	--enable-languages=ada,c,c++
CONFIGURE_ARGS+=	--disable-bootstrap
CONFIGURE_ARGS+=	--disable-shared
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-multilib
CONFIGURE_ARGS+=	--enable-long-long
CONFIGURE_ARGS+=	--with-local-prefix=${PREFIX}/${PKGBASE}
CONFIGURE_ARGS+=	--enable-threads=posix
CONFIGURE_ARGS+=	--without-zstd
CONFIGURE_ARGS+=	--without-system-zlib
CONFIGURE_ARGS+=	--enable-__cxa_atexit
CONFIGURE_ARGS+=	--with-gxx-include-dir=${PREFIX}/${PKGBASE}/include/c++/
CONFIGURE_ARGS+=	--disable-libstdcxx-pch
CONFIGURE_ARGS+=	--disable-lto

.if !empty(OSX_SDK_PATH)
CONFIGURE_ARGS.Darwin+=	--with-sysroot=${OSX_SDK_PATH:Q}
.endif
CONFIGURE_ARGS.NetBSD+=	--with-gnu-ld --with-ld=/usr/bin/ld
CONFIGURE_ARGS.NetBSD+=	--with-gnu-as --with-as=/usr/bin/as

MAKE_ENV.NetBSD+=	ac_cv_func_clock_gettime=yes
MAKE_ENV.NetBSD+=	ac_cv_func_gethostbyname_r=no
MAKE_ENV.NetBSD+=	ac_cv_func_freelocale=no
MAKE_ENV.NetBSD+=	ac_cv_func_newlocale=no
MAKE_ENV.NetBSD+=	ac_cv_func_uselocale=no
MAKE_ENV.SunOS+=	ac_cv_func_mkostemp=no

.if ${MACHINE_PLATFORM:MNetBSD-*-i386} || ${MACHINE_PLATFORM:MLinux-*-i386}
CONFIGURE_ARGS+=	--with-arch=i486 --with-tune=i486
.endif

.if ${MACHINE_PLATFORM:MNetBSD-*-x86_64} || ${MACHINE_PLATFORM:MLinux-*-x86_64}
CONFIGURE_ARGS+=	--with-arch=nocona --with-tune=nocona --with-fpmath=sse
.endif

.if ${MACHINE_PLATFORM:MDarwin-[0-8].*-*}
CONFIGURE_ARGS+=	--with-dwarf2
.endif

# ${WRKSRC}/fixincludes/ looks for sed and compiles the path to sed into
# a binary so we need to make sure we give it the installed sed and not
# the tool wrapped one.
MAKE_ENV+=		ac_cv_path_SED=${TOOLS_SED}
MAKE_ENV+=		lt_cv_path_SED=${TOOLS_SED}

.include "../../devel/binutils/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gnu-as --with-as=${PREFIX}/bin/gas

CTF_FILES_SKIP+=	*/gengtype	# CPU limit exceeded

post-install:
	cd ${DESTDIR}${PREFIX} && \
	find ${PKGBASE} \
	    \( -type f -or -type l \) -and \
	    \( -path ${PKGBASE}/bin/\* -or -path ${PKGBASE}/include/\* -or \
		-path ${PKGBASE}/lib/\* -or -path ${PKGBASE}/libexec/\* \) -and \
	    ! -path ${PKGBASE}/bin/${MACHINE_GNU_PLATFORM}\* -and \
	    ! -path ${PKGBASE}/lib/\*/include-fixed/\* \
	    -print | \
	${PAX} -wd | \
	${BZIP2} >${WRKDIR}/${PKGBASE}-${MACHINE_GNU_PLATFORM}-${PKGVERSION_NOREV}.tar.bz2

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${PKGBASE} \( -type f -o -type l \) -print | ${SORT};

.include "../../devel/gmp/inplace.mk"
.include "../../math/mpcomplex/inplace.mk"
.include "../../math/mpfr/inplace.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

CC=	${PREFIX}/gcc10-aux/bin/gcc
CXX=	${PREFIX}/gcc10-aux/bin/g++

PREPEND_PATH+=	${PREFIX}/gcc10-aux/bin

CFLAGS=		-O2
CPPFLAGS=	#empty
CXXFLAGS=	-O2
LDFLAGS=	-static -static-libstdc++ -static-libgcc
