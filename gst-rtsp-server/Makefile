# $NetBSD: Makefile,v 1.9 2021/12/08 16:05:59 adam Exp $

DISTNAME=	gst-rtsp-server-1.19.2
CATEGORIES=	net multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-rtsp-server/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/modules/gst-rtsp-server.html
COMMENT=	GStreamer RTSP server
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=			pkg-config msgfmt xgettext
PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		lib/pkgconfig/gstreamer-rtsp-server-1.0.pc
PYTHON_FOR_BUILD_ONLY=		tool

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gst/rtsp-server

BUILDLINK_API_DEPENDS.gobject-introspection+=		gobject-introspection>=1.7.0
BUILDLINK_DEPMETHOD.gobject-introspection+=     build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.40.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
