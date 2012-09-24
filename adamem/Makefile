# $NetBSD: Makefile,v 1.10 2012/09/24 16:20:20 asau Exp $
#

DISTNAME=		adamem
PKGNAME=		adamem-1.0
CATEGORIES=		emulators
MASTER_SITES=		http://www.komkon.org/~dekogel/files/coleco/

MAINTAINER=		xmor61@users.sourceforge.net
HOMEPAGE=		http://www.komkon.org/~dekogel/adamem.html
COMMENT=		Emulator for the Colecovision game console and Adam computer system

MAKE_FILE=		Makefile.X
WRKSRC=			${WRKDIR}

SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	post-patch
SUBST_MESSAGE.dsp=	Adjusting sound device path.
SUBST_FILES.dsp=	dev_dsp.h
SUBST_SED.dsp=		-e "s|/dev/dsp|${DEVOSSAUDIO}|"

SUBST_CLASSES+=		adam
SUBST_STAGE.adam=	pre-configure
SUBST_FILES.adam=	adam
SUBST_SED.adam+=	-e 's|<!--ADAMEM_DIR-->|${PREFIX}/share/adamem|g'
SUBST_SED.adam+=	-e 's|<!--BIN_DIR-->|${PREFIX}/bin|g'

CPPFLAGS.i386+=		-DX86_ASM

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "little"
CPPFLAGS+=		-DLSB_FIRST
.endif

post-extract:
	${CP} ${FILESDIR:Q}/adam ${WRKSRC:Q}/

do-install:
.for f in adamem cvem z80dasm snapedit
	${INSTALL_PROGRAM} ${WRKSRC:Q}/${f:Q} ${DESTDIR}${PREFIX:Q}/bin
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX:Q}/share/adamem
	${INSTALL_DATA} ${WRKSRC:Q}/adamem.txt ${DESTDIR}${PREFIX:Q}/share/adamem
	${INSTALL_DATA} ${WRKSRC:Q}/adamem.snd ${DESTDIR}${PREFIX:Q}/share/adamem
.for f in OS7 EOS WP
	${INSTALL_DATA} ${WRKSRC:Q}/${f:Q}.rom ${DESTDIR}${PREFIX:Q}/share/adamem
.endfor
	${INSTALL_SCRIPT} ${WRKSRC:Q}/adam ${DESTDIR}${PREFIX:Q}/bin/adam
	${RM} -f ${DESTDIR}${PREFIX:Q}/bin/coleco
	${LN} -s adam ${DESTDIR}${PREFIX:Q}/bin/coleco

.include "../../devel/allegro/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
