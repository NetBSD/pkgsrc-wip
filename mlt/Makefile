# $NetBSD: Makefile,v 1.97 2019/07/21 22:25:27 wiz Exp $

.include "Makefile.common"

CATEGORIES=	multimedia

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mltframework.org/
COMMENT=	Open source multimedia framework
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++11
HAS_CONFIGURE=	yes

# C++11
GCC_REQD+=	4.9

CPPFLAGS.NetBSD+=	-DHAVE_LOCALE_H

CONFIGURE_ARGS+=	--enable-gpl
CONFIGURE_ARGS+=	--enable-gpl3
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

PKGCONFIG_OVERRIDE+=	mlt++.pc.in
PKGCONFIG_OVERRIDE+=	mlt-framework.pc.in

post-configure:
	${TOUCH} ${WRKSRC}/src/modules/disable-jackrack
	${TOUCH} ${WRKSRC}/src/modules/disable-ndi
	${TOUCH} ${WRKSRC}/src/modules/disable-swfdec
	# disable this until flowblade supports it
	# https://github.com/jliljebl/flowblade/issues/603
	${TOUCH} ${WRKSRC}/src/modules/disable-sdl2

.include "../../audio/libebur128/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/sox/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/frei0r/buildlink3.mk"
.include "../../multimedia/movit/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
