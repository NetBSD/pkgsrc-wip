# $NetBSD: Makefile,v 1.6 2015/07/13 10:30:47 roelants Exp $

DISTNAME=	deadbeef-1.8.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=DeaDBeeF-Player/}

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	https://deadbeef.sourceforge.io/
COMMENT=	Modular music player
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	autopoint aclocal autoheader autoconf automake
USE_TOOLS+=	gmake intltool pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_TOOLS+=	bison perl

TOOL_DEPENDS+=	yasm-[0-9]*:../../devel/yasm

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
CONFIGURE_ARGS+=	--enable-oss
MAKE_ENV+=		OSS_LIBS=${LIBOSSAUDIO}
.else
CONFIGURE_ARGS+=	--disable-oss
.endif

# using mpg123 instead
CONFIGURE_ARGS+=	--disable-libmad

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "options.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/musepack/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
