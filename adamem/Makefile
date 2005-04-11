# $NetBSD: Makefile,v 1.3 2005/04/11 21:09:39 tvierling Exp $
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

SUBST_CLASSES+=         dsp
SUBST_STAGE.dsp=        post-patch
SUBST_MESSAGE.dsp=      Adjusting sound device path.
SUBST_FILES.dsp=        dev_dsp.h
SUBST_SED.dsp=          -e "s|/dev/dsp|${DEVOSSAUDIO}|"

.if ${MACHINE_ARCH} == "i386"
CPPFLAGS+=		-DX86_ASM
.endif

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "little"
CPPFLAGS+=		-DLSB_FIRST
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
	${SED} 	-e "s|<!--ADAMEM_DIR-->|${PREFIX}/share/adamem|" \
		-e "s|<!--BIN_DIR-->|${PREFIX}/bin|" \
		${FILESDIR}/adam > ${PREFIX}/bin/adam
	${CHMOD} 755 ${PREFIX}/bin/adam
	${LN} -s ${PREFIX}/bin/adam ${PREFIX}/bin/coleco

.include "../../devel/allegro/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
