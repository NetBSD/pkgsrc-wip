# $NetBSD: Makefile,v 1.23 2014/05/18 15:17:51 wiz Exp $

DISTNAME=	libffi-3.0.13
PKGNAME=	frida-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=frida/}
GITHUB_TAG=	808ca2c69269f6df3ee6d33e22515d11739ffd5c

GITHUB_PROJECT=	libffi

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://www.sourceware.org/libffi/
COMMENT=	Foreign function interface
LICENSE=	mit

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/frida/include
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf automake makeinfo gmake
USE_LANGUAGES=	c c++
INFO_FILES=	yes

PKGCONFIG_OVERRIDE+=	libffi.pc.in

WRKSRC=		${WRKDIR}/libffi-${GITHUB_TAG}

.include "../../mk/compiler.mk"
# The Compaq C frontend groks .s, but not .S. Assemble osf.S directly w/ as(1).
pre-build:
.if !empty(PKGSRC_COMPILER:Mccc)
	cd ${WRKSRC} && ./libtool --mode=compile --tag=CC as -I. -Iinclude -o src/alpha/osf.lo -c src/alpha/osf.S
.endif

# Since we don't have "TEST_DEPENDS", we implement it as a hack:
.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
TEST_TARGET=	check
TEST_ENV=
BUILD_DEPENDS+=	dejagnu-[0-9]*:../../devel/dejagnu
.endif

# patch-aj uses m68k_sync_icache(2)
.if !empty(MACHINE_PLATFORM:MNetBSD-*-m68k)
LIBS+=	-lm68k
.endif

# fix http://gnats.netbsd.org/42865
.if !empty(MACHINE_PLATFORM:MSunOS-*-i386) && !empty(CC_VERSION:Mgcc-[23]*)
CPPFLAGS+=	-D__PIC__
.endif

# irix fixes from PR 48587
.if ${OPSYS} == IRIX
USE_TOOLS+=	bash gmake
MAKE_FLAGS+=	SHELL=${TOOLS_DIR}/bin/bash
.endif

FRIDA_SUBPREFIX=	frida
FRIDA_PREFIX=		${PREFIX}/${FRIDA_SUBPREFIX}
GNU_CONFIGURE_PREFIX=	${FRIDA_PREFIX}

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
