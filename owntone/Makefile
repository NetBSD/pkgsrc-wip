# $NetBSD$

VERSION=	28.12
DISTNAME=	owntone-${VERSION}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=owntone/owntone-server/releases/download/${VERSION}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://owntone.github.io/owntone-server/
COMMENT=	Media server for streaming your media library
LICENSE=	gnu-gpl-v2

OWNTONE_USER?=	owntone
OWNTONE_GROUP?=	owntone
PKG_GROUPS=	${OWNTONE_USER}
PKG_USERS=	${OWNTONE_USER}:${OWNTONE_GROUP}

RCD_SCRIPTS=	owntone

#CONF_FILES=	etc/owntone.conf

GNU_CONFIGURE=	yes

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	flex
USE_TOOLS+=	bison

CONFIGURE_ARGS+=	--disable-install_systemd

# Fight ffmpeg/libav
#
# Letting pkg-config find it didn't seem to work; and then
# configure.ac tries to perform a link (reasonable really).

LIBAV_CFLAGS+=		-I${BUILDLINK_PREFIX.ffmpeg5}/include/ffmpeg5
LIBAV_LIBS+=		${BUILDLINK_PREFIX.ffmpeg5}/lib/ffmpeg5/libavformat.so
LIBAV_LIBS+=		${BUILDLINK_PREFIX.ffmpeg5}/lib/ffmpeg5/libavcodec.so
LIBAV_LIBS+=		${BUILDLINK_PREFIX.ffmpeg5}/lib/ffmpeg5/libavfilter.so
LIBAV_LIBS+=		${BUILDLINK_PREFIX.ffmpeg5}/lib/ffmpeg5/libavutil.so
# Help configure.ac find libdav1d
LIBAV_LIBS+=		${BUILDLINK_PREFIX.dav1d}/lib/libdav1d.so

CONFIGURE_ENV+=		'LIBAV_CFLAGS=${LIBAV_CFLAGS}'
CONFIGURE_ENV+=		'LIBAV_LIBS=${LIBAV_LIBS}'

BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0.0
#BUILDLINK_API_DEPENDS.protobuf-c=	protbuf-c>=1.3.3nb2

.include "../../net/avahi/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../multimedia/ffmpeg5/buildlink3.mk"
.include "../../devel/confuse/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../textproc/mxml/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libplist/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../www/libwebsockets/buildlink3.mk"

.include "../../devel/libinotify/buildlink3.mk"
.include "../../multimedia/dav1d/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
