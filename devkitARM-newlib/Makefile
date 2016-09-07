# $NetBSD$

DISTNAME=	devkitARM-newlib-45
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=devkitPro/}
GITHUB_PROJECT=	newlib
GITHUB_TAG=	f75b38917dc5daf8e31000067d60b66604c39434

MAINTAINER=	js@heap.zone
HOMEPAGE=	http://devkitpro.org/
COMMENT=	Newlib for devkitARM toolchain
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2.1 AND gnu-lgpl-v3 AND modified-bsd

WRKSRC=		${WRKDIR}/newlib-f75b38917dc5daf8e31000067d60b66604c39434
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	../newlib-${GITHUB_TAG}/configure
GNU_CONFIGURE_PREFIX=	${PREFIX}/devkitpro/devkitARM
CONFIGURE_ARGS+=	--target=arm-none-eabi
CONFIGURE_ARGS+=	--disable-newlib-supplied-syscalls
CONFIGURE_ARGS+=	--enable-newlib-mb
CONFIGURE_ARGS+=	CC_FOR_TARGET=arm-none-eabi-gcc
CONFIGURE_ARGS+=	CXX_FOR_TARGET=arm-none-eabi-g++

DEPENDS=	cross-arm-none-eabi-gcc>=5.3:../../cross/arm-none-eabi-gcc5

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

do-build:
	cd ${WRKDIR}/build && \
	${SETENV} PATH="${PREFIX}/cross-arm-none-eabi/bin:${PATH}" \
	${GMAKE}

do-install:
	cd ${WRKDIR}/build && \
	${SETENV} PATH="${PREFIX}/cross-arm-none-eabi/bin:${PATH}" \
	${GMAKE} DESTDIR=${DESTDIR} install

.include "../../mk/bsd.pkg.mk"
