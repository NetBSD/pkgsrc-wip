# $NetBSD: Makefile,v 1.1.1.1 2005/01/11 19:48:05 xmor61 Exp $
#

DISTNAME=		adamem
PKGNAME=		adamem-1.0
CATEGORIES=		emulators
MASTER_SITES=		http://www.komkon.org/~dekogel/files/coleco/

MAINTAINER=		xmor61@users.sourceforge.net
HOMEPAGE=		http://www.komkon.org/~dekogel/adamem.html
COMMENT=		Emulator for the Colecovision game console and Adam computer system

MAKEFILE=		Makefile.X
USE_X11=		YES
WRKSRC=		        ${WRKDIR}
USE_BUILDLINK3=		yes

SUBST_CLASSES+=         dsp
SUBST_STAGE.dsp=        post-patch
SUBST_MESSAGE.dsp=      Adjusting sound device path.
SUBST_FILES.dsp=        dev_dsp.h
SUBST_SED.dsp=          -e "s|/dev/dsp|${DEVOSSAUDIO}|"

.if ${MACHINE_ARCH} == "i386"
SUBST_CLASSES+=         asm
SUBST_STAGE.asm=        post-patch
SUBST_MESSAGE.asm=      Adjusting Makefile for in-line asm on i386.
SUBST_FILES.asm=        Makefile.X
SUBST_SED.asm=          -e "s|-DUNIX_X -DUNIX|-DUNIX_X -DUNIX -DX86_ASM|"
.endif

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "little"
SUBST_CLASSES+=         lsb
SUBST_STAGE.lsb=        post-patch
SUBST_MESSAGE.lsb=      Adjusting Makefile for LITTLE_ENDIAN arch.
SUBST_FILES.lsb=        Makefile.X
SUBST_SED.lsb=          -e "s|-DUNIX_X -DUNIX|-DUNIX_X -DUNIX -DLSB_FIRST|"
.endif

do-install:
.for EXE in adamem cvem z80dasm snapedit
	${INSTALL_PROGRAM} ${WRKSRC}/${EXE} ${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/adamem
	${INSTALL_DATA} ${WRKSRC}/adamem.txt ${PREFIX}/share/adamem
	${INSTALL_DATA} ${WRKSRC}/adamem.snd ${PREFIX}/share/adamem
.for ROM in OS7 EOS WP
	${INSTALL_DATA} ${WRKSRC}/${ROM}.rom ${PREFIX}/share/adamem
.endfor

.include "../../mk/bsd.pkg.mk"
.include "../../devel/allegro/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
