# $NetBSD: Makefile,v 1.6 2007/03/25 20:43:30 thomasklausner Exp $
#

DISTNAME=		sdlmame0113
PKGNAME=		sdlmame-0.113
CATEGORIES=		emulators
MASTER_SITES=		http://rbelmont.mameworld.info/
EXTRACT_SUFX=		.zip

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://rbelmont.mameworld.info/?page_id=163
COMMENT=		Multiple Arcade Machine Emulator, SDL port

RESTRICTED=		selling is not allowed
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_TOOLS+=             gmake
UNLIMIT_RESOURCES=      datasize
MAKE_FILE=              makefile
LICENSE=		mame-license

.if ${MACHINE_ARCH:Mi386}
X86_MIPS3_DRC = 1
X86_PPC_DRC = 1
#PKG_DEFS+=	-DX86_ASM
.else
X86_MIPS3_DRC =
X86_PPC_DRC =
.endif
.if ${MACHINE_ARCH:Mppc}
PKG_DEFS+=	-DPPC_ASM
.endif

.  include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN:Mlittle}
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
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sdlmame
	${INSTALL_DATA} ${WRKSRC}/SDLMAME.txt ${PREFIX}/share/doc/sdlmame
	${INSTALL_DATA} ${WRKSRC}/docs/license.txt ${PREFIX}/share/doc/sdlmame
	${INSTALL_DATA} ${WRKSRC}/docs/mame.txt ${PREFIX}/share/doc/sdlmame
	${INSTALL_DATA} ${WRKSRC}/docs/windows.txt ${PREFIX}/share/doc/sdlmame

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
