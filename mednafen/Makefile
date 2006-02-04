# $NetBSD: Makefile,v 1.9 2006/02/04 17:30:16 thomasklausner Exp $
#

DISTNAME=	mednafen-0.4.8
CATEGORIES=	emulators
MASTER_SITES=	http://mednafen.com/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mednafen.com/
COMMENT=	Portable multi-system emulator

WRKSRC=			${WRKDIR}/mednafen
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	pre-configure
SUBST_MESSAGE.dsp=	Fixing path to audio device.
SUBST_FILES.dsp=	src/sexyal/drivers/esd.c src/sexyal/drivers/oss.c \
			src/sexyal/drivers/oss.c src/sexyal/sexyal.c
SUBST_SED.dsp=		s,/dev/dsp,${DEVOSSAUDIO},

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mednafen
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mednafen/tech
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mednafen/tech/cpu
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mednafen/tech/exp
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mednafen/tech/ppu
	${INSTALL_DATA} ${WRKSRC}/Documentation/*.html \
		${PREFIX}/share/doc/mednafen
	${INSTALL_DATA} ${WRKSRC}/Documentation/*.txt \
		${PREFIX}/share/doc/mednafen
	${INSTALL_DATA} ${WRKSRC}/Documentation/tech/*.* \
		${PREFIX}/share/doc/mednafen/tech
	${INSTALL_DATA} ${WRKSRC}/Documentation/tech/cpu/*.* \
		${PREFIX}/share/doc/mednafen/tech/cpu
	${INSTALL_DATA} ${WRKSRC}/Documentation/tech/exp/*.* \
		${PREFIX}/share/doc/mednafen/tech/exp
	${INSTALL_DATA} ${WRKSRC}/Documentation/tech/ppu/*.* \
		${PREFIX}/share/doc/mednafen/tech/ppu

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
