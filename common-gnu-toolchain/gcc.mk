# $NetBSD$

GCC_VERSION?=		14.3.0

.if ${GCC_VERSION} == 14.3.0
NEWLIBVER?=		4.5.0.20241231
DEPENDS+=		cross-${TARGET}-binutils>=2.45:../../cross/${TARGET}-binutils
.elif ${GCC_VERSION} == 13.2.0
NEWLIBVER=		4.3.0.20230120
DEPENDS+=		cross-${TARGET}-binutils>=2.42:../../cross/${TARGET}-binutils
.endif

DISTNAME?=		gcc-${GCC_VERSION}
PKGNAME?=		cross-${TARGET}-${DISTNAME}
#PKGREVISION?=		1
CATEGORIES=		cross
MASTER_SITES?=		${MASTER_SITE_GNU:=gcc/gcc-${PKGVERSION_NOREV}/}
EXTRACT_SUFX?=		.tar.xz
DISTFILES?=		${DEFAULT_DISTFILES} \
			newlib-${NEWLIBVER}.tar.gz
SITES.newlib-${NEWLIBVER}.tar.gz?=	https://www.sourceware.org/pub/newlib/

HOMEPAGE=		# none
LICENSE?=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

EXTRACT_USING=		bsdtar

# for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33549
# use makeinfo from pkgsrc/devel/gtexinfo.
# FIXME: We probably still need pkgsrc makeinfo in NetBSD 10.
#TEXINFO_REQD=		5.1

USE_LANGUAGES+=		c c++

TOOLCHAIN_PREFIX=	${PREFIX}/cross-${TARGET}
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure

CONFIG_SHELL=		${TOOLS_PATH.bash}
WRAPPER_SHELL=		${TOOLS_PATH.bash}
USE_TOOLS+=		bash gmake gsed makeinfo perl
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # has sub-configures
CHECK_PORTABILITY_SKIP+=contrib/*
MKPIE_SUPPORTED=	no # relocation errors on netbsd-9 aarch64

GNU_CONFIGURE_PREFIX=	${TOOLCHAIN_PREFIX}

CONFIGURE_ARGS+=	--target=${TARGET}
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-libstdcxx-pch
CONFIGURE_ARGS+=	--disable-gcov
CONFIGURE_ARGS+=	--enable-multilib

INFO_FILES=		yes

# PLIST_VARS+=		libcpp

# .include "../../mk/bsd.prefs.mk"
# .if ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS" || ${OPSYS} == "Darwin"
# PLIST.libcpp=	yes
# .endif

DISTINFO_FILE?=	${.CURDIR}/../../cross/common-gnu-toolchain/distinfo-${DISTNAME}
PATCHDIR?=	${.CURDIR}/../../cross/common-gnu-toolchain/patches-${DISTNAME}

post-extract:
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/newlib ${WRKSRC}/newlib
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/libgloss ${WRKSRC}/libgloss

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
