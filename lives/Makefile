# $NetBSD: Makefile,v 1.8 2010/01/18 09:38:27 thomasklausner Exp $
#

DISTNAME=	LiVES-0.9.9.9
LIVESVERS=	0.9.9.9
PKGNAME=	lives-${LIVESVERS}
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.xs4all.nl/%7Esalsaman/lives/current/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://lives.sourceforge.net/
COMMENT=	Linux Video Editing System
LICENSE=	gnu-gpl-v3

DEPENDS+=	sox-[0-9]*:../../audio/sox
DEPENDS+=	mplayer>=1.0rc1:../../multimedia/mplayer
DEPENDS+=	mencoder>=1.0rc1:../../multimedia/mencoder

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${PKGNAME}
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	pkg-config perl gmake intltool msgfmt

REPLACE_PERL+=	build-lives-rfx-plugin-multi build-lives-rfx-plugin \
		tools/autolives.pl \
		smogrify \
		lives-plugins/plugins/encoders/encodedv_encoder \
		lives-plugins/plugins/encoders/ffmpeg_encoder  \
		lives-plugins/plugins/encoders/mencoder_encoder \
		lives-plugins/plugins/encoders/qtutils_encoder \
		lives-plugins/plugins/encoders/mjpegtools_encoder \
		lives-plugins/plugins/encoders/pdf_encoder \
		lives-plugins/plugins/encoders/qtutils_encoder \
		lives-plugins/plugins/encoders/sswf_encoder \
		lives-plugins/plugins/encoders/transcode_encoder

.include "options.mk"

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../multimedia/libdv/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
