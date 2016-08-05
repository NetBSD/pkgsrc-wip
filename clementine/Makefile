# $NetBSD$

DISTNAME=	clementine-1.3.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=clementine-player/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_PROJECT=	Clementine

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.clementine-player.org/
COMMENT=	Cross-platform music player inspired by Amarok 1.4
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME:S/c/C/}
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	3rdparty/libprojectm/libprojectM.pc.in

LDFLAGS.NetBSD+=	-lexecinfo # for backtrace()

#   libgpod (optional, for iPod support)
#   libplist (optional, for iPod support)
#   libusbmuxd (optional, for iPod support)
#   libmtp (optional, for MTP support)
#   libgio (optional, for various device support)
#   libcdio (optional, for CD support)
.include "../../misc/libcdio/buildlink3.mk"
#   libspotify (optional, for Spotify support)
#   libcrypto++ (optional, for Spotify support)
#   libsparsehash (optional, for Google Drive/Dropbox/Box/Skydrive support)
#   libpulse (optional, for choosing output devices)

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../audio/liblastfm/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/chromaprint/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../devel/qjson/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
# all below here supposedly optional, but not really
.include "../../security/crypto++/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
