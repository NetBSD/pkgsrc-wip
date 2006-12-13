# $NetBSD: Makefile,v 1.1.1.1 2006/12/13 22:50:33 dillo Exp $
#

DISTNAME=		sdlmame0109
PKGNAME=		sdlmame-0.109
CATEGORIES=		emulators
MASTER_SITES=		http://rbelmont.mameworld.info/
EXTRACT_SUFX=		.zip

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://rbelmont.mameworld.info/
COMMENT=		Multiple Arcade Machine Emulator, SDL port

RESTRICTED=		selling is not allowed
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_TOOLS+=             gmake
UNLIMIT_RESOURCES=      datasize
MAKE_FILE=              makefile

.if ${MACHINE_ARCH:Mi386}
X86_MIPS3_DRC = 1
X86_PPC_DRC = 1
#PKG_DEFS+=	-DX86_ASM
.else
X86_MIPS3_DRC = 0
X86_PPC_DRC = 0
.endif
.if ${MACHINE_ARCH:Mppc}
PKG_DEFS+=	-DPPC_ASM
.endif

.  include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN:Mlittle-endian}
PKG_DEFS+=	-DLSB_FIRST
.endif

PKG_DEFS+=	-DSDLMAME_NO64BITIO
# XXX: PTR64
MAKE_FLAGS+=	PKG_DEFS=${PKG_DEFS:Q}
MAKE_FLAGS+=	X86_MPIS3_DRC=${X86_MIPS3_DRC:Q}
MAKE_FLAGS+=	X86_PPC_DRC=${X86_PPC_DRC:Q}

# Pragma once is not needed, and creates warnings/errors on gcc
SUBST_CLASSES+=         pragma
SUBST_STAGE.pragma=     pre-configure
SUBST_FILES.pragma=     src/*.h src/*/*.h
SUBST_SED.pragma=       -e "s|\#pragma once||g"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mame ${LOCALBASE}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
