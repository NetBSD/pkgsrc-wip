# $NetBSD: Makefile,v 1.1 2013/06/12 12:12:09 othyro Exp $

DISTNAME=	SDL2_mixer-2.0.0
CATEGORIES=	audio
MASTER_SITES=	http://www.libsdl.org/tmp/SDL_mixer/release/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/tmp/SDL_mixer/
COMMENT=	Sample multi-channel audio mixer library
LICENSE=	zlib

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	SDL2_mixer.pc.in
PKGCONFIG_OVERRIDE+=	external/flac-1.2.1/src/libFLAC/flac.pc.in
PKGCONFIG_OVERRIDE+=	external/flac-1.2.1/src/libFLAC++/flac++.pc.in
PKGCONFIG_OVERRIDE+=	external/libmodplug-0.8.8.4/libmodplug.pc.in
PKGCONFIG_OVERRIDE+=	external/libogg-1.3.1/ogg.pc.in
PKGCONFIG_OVERRIDE+=	external/libvorbis-1.3.3/vorbis.pc.in
PKGCONFIG_OVERRIDE+=	external/libvorbis-1.3.3/vorbisenc.pc.in
PKGCONFIG_OVERRIDE+=	external/libvorbis-1.3.3/vorbisfile.pc.in
PKGCONFIG_OVERRIDE+=	external/libvorbisidec-1.2.1/vorbisidec.pc.in

.include "options.mk"

CONFIGURE_ARGS+=	--enable-music-mp3-smpeg=no --disable-smpegtest

# XXX http://forums.libsdl.org/viewtopic.php?p=37449&sid=cb779c24fba69bff5ba36046daf82d78#37449

.include "../../wip/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
