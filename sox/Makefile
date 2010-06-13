# $NetBSD: Makefile,v 1.2 2010/06/13 22:47:16 thomasklausner Exp $

DISTNAME=	sox-14.2.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sox.sourceforge.net/
COMMENT=	SOund eXchange - universal sound sample translator

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=			pkg-config

# Disable any system-dependent audio drivers not to pollute PLIST.
CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-oss
CONFIGURE_ARGS+=	--disable-sun-audio
CONFIGURE_ARGS+=	--disable-coreaudio

# LADSPA isn't available for all platforms.
CONFIGURE_ARGS+=	--without-ladspa

# ffmpeg tends to change its API very frequently and its user
# applications suffer from compilation failure.
CONFIGURE_ARGS+=	--without-ffmpeg

# lame may cause a license problem.
CONFIGURE_ARGS+=	--without-lame

# AMR Codecs are not yet available on pkgsrc.
# See http://www.penguin.cz/~utx/amr
CONFIGURE_ARGS+=	--without-amr-wb
CONFIGURE_ARGS+=	--without-amr-nb

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/gsm/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
