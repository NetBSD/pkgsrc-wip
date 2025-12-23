# $NetBSD$

DISTNAME=	pipewire-1.4.7
CATEGORIES=	multimedia
MASTER_SITES=	https://gitlab.freedesktop.org/pipewire/pipewire/-/archive/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://pipewire.org/
COMMENT=	Low-latency, graph-based processing engine for audio and video
LICENSE=	mit

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		gnu11 c++
USE_TOOLS+=		msgfmt pkg-config xgettext

CPPFLAGS.NetBSD+=	-UHAVE_MEMFD_CREATE

CFLAGS.NetBSD+=	-D__LOCALE_C_ONLY
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE #should be _POSIX_C_SOURCE or _XOPEN_COURCE

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Linux"
.include "../../devel/libepoll-shim/buildlink3.mk"
CFLAGS+=	-I${BUILDLINK_PREFIX.libepoll-shim}/include/libepoll-shim
LDFLAGS+=	-lepoll-shim
.endif

BUILDLINK_TRANSFORM+=	rm:-Werror=format # %m in printf

LDFLAGS+=	-L${PREFIX}/lib/pipewire-0.3
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/pipewire-0.3

# Only relevant on linux, install clashes with /etc/security script on NetBSD
#CONF_FILES+=	${PREFIX}/share/examples/pipewire/25-pw-rlimits.conf \
#		${PKG_SYSCONFDIR}/security/limits.d/25-pw-rlimits.conf

MESON_ARGS+=	-Dv4l2=disabled
MESON_ARGS+=	-Dpipewire-v4l2=disabled
MESON_ARGS+=	-Dsession-managers=disabled
MESON_ARGS+=	-Dtest=disabled
MESON_ARGS+=	-Dtests=disabled
MESON_ARGS+=	-Dexamples=disabled
MESON_ARGS+=	-Dlegacy-rtkit=false
MESON_ARGS+=	-Dlibpulse=disabled
MESON_ARGS+=	-Draop=disabled
MESON_ARGS+=	-Dsdl2=disabled

# Enable these for usual installation
MESON_ARGS+=	-Dalsa=disabled
MESON_ARGS+=	-Dpipewire-alsa=disabled

#.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libmysofa/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/lilv/buildlink3.mk"
#.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
#.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
#.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
# For Linux?
#.include "../../graphics/libv4l/buildlink3.mk"
#.include "../../sysutils/libudev/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
