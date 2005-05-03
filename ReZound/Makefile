# $NetBSD: Makefile,v 1.1.1.1 2005/05/03 17:13:49 cetrox Exp $
#

DISTNAME=		rezound-0.11.1beta
PKGNAME=		ReZound-0.11.1
CATEGORIES=		audio
MASTER_SITES=		http://aleron.dl.sourceforge.net/sourceforge/rezound/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://rezound.sourceforge.net/
COMMENT=		Audio editor

BUILD_DEPENDS+= 	bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=		cdrdao>=1.1.9:../../sysutils/cdrdao

CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-jack
CONFIGURE_ARGS+=	--enable-oss
CONFIGURE_ARGS+=	--enable-portaudio
LDFLAGS+=		-lcompat
USE_GNU_TOOLS+=		lex make
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_X11=		yes
YACC=			bison

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../math/fftw2/buildlink3.mk"
.include "../../wip/libSoundTouch/buildlink3.mk"
.include "../../wip/fox/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
