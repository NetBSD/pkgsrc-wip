# $NetBSD: Makefile,v 1.4 2005/11/23 18:40:39 leonardschmidt Exp $
#

DISTNAME=	mednafen-0.3.7
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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mednafen
	${INSTALL_DATA} ${WRKSRC}/Documentation/*.html \
		${PREFIX}/share/doc/mednafen
	${INSTALL_DATA} ${WRKSRC}/Documentation/*.txt \
		${PREFIX}/share/doc/mednafen

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
