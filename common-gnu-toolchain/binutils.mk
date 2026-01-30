# $NetBSD$

DISTNAME?=	binutils-2.45
PKGNAME?=	cross-${TARGET}-${DISTNAME}
#PKGREVISION?=	1
CATEGORIES=	cross
MASTER_SITES?=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX?=	.tar.xz

HOMEPAGE=	# empty
LICENSE?=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo perl
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # several sub-configures know --enable-nls

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure

CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--target=${TARGET}
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--enable-deterministic-archives
INFO_FILES=		yes

TOOLCHAIN_PREFIX=	${PREFIX}/cross-${TARGET}

GNU_CONFIGURE_PREFIX=	${TOOLCHAIN_PREFIX}

DISTINFO_FILE?=	${.CURDIR}/../../wip/common-gnu-toolchain/distinfo-binutils
PATCHDIR?=	${.CURDIR}/../../wip/common-gnu-toolchain/patches-binutils

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

post-install:
	${RM} ${DESTDIR}${TOOLCHAIN_PREFIX}/${TARGET}/lib/ldscripts/stamp
