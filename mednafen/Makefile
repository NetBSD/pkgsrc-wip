# $NetBSD: Makefile,v 1.3 2005/11/23 17:53:08 leonardschmidt Exp $
#

DISTNAME=	mednafen-0.3.7
CATEGORIES=	emulators
MASTER_SITES=	http://mednafen.com/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://mednafen.com/
COMMENT=	Portable multi-system emulator

WRKSRC=			${WRKDIR}/mednafen
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
