# $NetBSD: Makefile,v 1.21 2015/09/07 13:10:43 thomasklausner Exp $

DISTNAME=	xpra-0.15.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	http://xpra.org/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xpra.org/
COMMENT=	screen(1) for X
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-cython>=0.14:../../devel/py-cython

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-gtk2

REPLACE_PYTHON+=	tests/__init__.py
REPLACE_PYTHON+=	tests/scripts/__init__.py
REPLACE_PYTHON+=	tests/xpra/__init__.py
REPLACE_PYTHON+=	tests/xpra/clients/__init__.py
REPLACE_PYTHON+=	tests/xpra/clipboard/__init__.py
REPLACE_PYTHON+=	tests/xpra/codecs/__init__.py
REPLACE_PYTHON+=	tests/xpra/codecs/x264/__init__.py
REPLACE_PYTHON+=	tests/xpra/gl/__init__.py
REPLACE_PYTHON+=	tests/xpra/gtk_common/__init__.py
REPLACE_PYTHON+=	tests/xpra/info/__init__.py
REPLACE_PYTHON+=	tests/xpra/keyboard/__init__.py
REPLACE_PYTHON+=	tests/xpra/net/__init__.py
REPLACE_PYTHON+=	tests/xpra/server/__init__.py
REPLACE_PYTHON+=	tests/xpra/servers/__init__.py
REPLACE_PYTHON+=	tests/xpra/session/__init__.py
REPLACE_PYTHON+=	tests/xpra/test_apps/__init__.py
REPLACE_PYTHON+=	tests/xpra/x11/__init__.py
REPLACE_PYTHON+=	tests/xpra/x11/bindings/__init__.py
REPLACE_PYTHON+=	win32/__init__.py
REPLACE_PYTHON+=	cups/xpraforwarder
REPLACE_PYTHON+=	xpra/__init__.py
REPLACE_PYTHON+=	xpra/client/__init__.py
REPLACE_PYTHON+=	xpra/client/gl/__init__.py
REPLACE_PYTHON+=	xpra/client/gl/gl_check.py
REPLACE_PYTHON+=	xpra/client/gtk2/__init__.py
REPLACE_PYTHON+=	xpra/client/gtk2/gtk2_notifier.py
REPLACE_PYTHON+=	xpra/client/gtk3/__init__.py
REPLACE_PYTHON+=	xpra/client/gtk_base/__init__.py
REPLACE_PYTHON+=	xpra/client/gtk_base/about.py
REPLACE_PYTHON+=	xpra/client/gtk_base/bug_report.py
REPLACE_PYTHON+=	xpra/client/gtk_base/client_launcher.py
REPLACE_PYTHON+=	xpra/client/gtk_base/gtk_version_info.py
REPLACE_PYTHON+=	xpra/client/notifications/__init__.py
REPLACE_PYTHON+=	xpra/client/notifications/pynotify_notifier.py
REPLACE_PYTHON+=	xpra/client/qt4/__init__.py
REPLACE_PYTHON+=	xpra/clipboard/__init__.py
REPLACE_PYTHON+=	xpra/codecs/__init__.py
REPLACE_PYTHON+=	xpra/codecs/argb/__init__.py
REPLACE_PYTHON+=	xpra/codecs/buffers/__init__.py
REPLACE_PYTHON+=	xpra/codecs/csc_cython/__init__.py
REPLACE_PYTHON+=	xpra/codecs/csc_opencl/__init__.py
REPLACE_PYTHON+=	xpra/codecs/csc_swscale/__init__.py
REPLACE_PYTHON+=	xpra/codecs/cuda_common/__init__.py
REPLACE_PYTHON+=	xpra/codecs/dec_avcodec/__init__.py
REPLACE_PYTHON+=	xpra/codecs/dec_avcodec2/__init__.py
REPLACE_PYTHON+=	xpra/codecs/enc_proxy/__init__.py
REPLACE_PYTHON+=	xpra/codecs/enc_x264/__init__.py
REPLACE_PYTHON+=	xpra/codecs/enc_x265/__init__.py
REPLACE_PYTHON+=	xpra/codecs/loader.py
REPLACE_PYTHON+=	xpra/codecs/nvenc/__init__.py
REPLACE_PYTHON+=	xpra/codecs/video_helper.py
REPLACE_PYTHON+=	xpra/codecs/vpx/__init__.py
REPLACE_PYTHON+=	xpra/codecs/webp/__init__.py
REPLACE_PYTHON+=	xpra/codecs/xor/__init__.py
REPLACE_PYTHON+=	xpra/gtk_common/__init__.py
REPLACE_PYTHON+=	xpra/gtk_common/gtk_spinner.py
REPLACE_PYTHON+=	xpra/gtk_common/gtk_view_clipboard.py
REPLACE_PYTHON+=	xpra/gtk_common/gtk_view_keyboard.py
REPLACE_PYTHON+=	xpra/gtk_common/keymap.py
REPLACE_PYTHON+=	xpra/keyboard/__init__.py
REPLACE_PYTHON+=	xpra/keyboard/mask.py
REPLACE_PYTHON+=	xpra/net/__init__.py
REPLACE_PYTHON+=	xpra/net/avahi_publisher.py
REPLACE_PYTHON+=	xpra/net/bencode/__init__.py
REPLACE_PYTHON+=	xpra/net/compression.py
REPLACE_PYTHON+=	xpra/net/net_util.py
REPLACE_PYTHON+=	xpra/net/packet_encoding.py
REPLACE_PYTHON+=	xpra/net/rencode/__init__.py
REPLACE_PYTHON+=	xpra/os_util.py
REPLACE_PYTHON+=	xpra/platform/__init__.py
REPLACE_PYTHON+=	xpra/platform/darwin/__init__.py
REPLACE_PYTHON+=	xpra/platform/win32/__init__.py
REPLACE_PYTHON+=	xpra/platform/xposix/__init__.py
REPLACE_PYTHON+=	xpra/scripts/__init__.py
REPLACE_PYTHON+=	xpra/server/__init__.py
REPLACE_PYTHON+=	xpra/server/auth/__init__.py
REPLACE_PYTHON+=	xpra/server/auth/pam.py
REPLACE_PYTHON+=	xpra/server/stats/__init__.py
REPLACE_PYTHON+=	xpra/sound/__init__.py
REPLACE_PYTHON+=	xpra/sound/gstreamer_util.py
REPLACE_PYTHON+=	xpra/sound/pulseaudio_util.py
REPLACE_PYTHON+=	xpra/sound/sink.py
REPLACE_PYTHON+=	xpra/sound/src.py
REPLACE_PYTHON+=	xpra/x11/__init__.py
REPLACE_PYTHON+=	xpra/x11/bindings/__init__.py
REPLACE_PYTHON+=	xpra/x11/dbus_helper.py
REPLACE_PYTHON+=	xpra/x11/gtk3_x11/__init__.py
REPLACE_PYTHON+=	xpra/x11/gtk_x11/__init__.py

INSTALLATION_DIRS+=	share/examples/py-xpra
OWN_DIRS+=		${PKG_SYSCONFDIR}/xpra
CONF_FILES+=		share/examples/py-xpra/xorg.conf ${PKG_SYSCONFDIR}/xpra/xorg.conf
CONF_FILES+=		share/examples/py-xpra/xpra.conf ${PKG_SYSCONFDIR}/xpra/xpra.conf

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"
SUBST_FILES.man+=	setup.py
SUBST_STAGE.man=	pre-build
SUBST_MESSAGE.man=	Fixing man page installation path.

post-install:
	cd ${DESTDIR}${PREFIX}/etc/xpra && \
		mv xorg.conf xpra.conf ${DESTDIR}${PREFIX}/share/examples/py-xpra

.include "../../devel/py-gobject-shared/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/ffmpeg1/buildlink3.mk"
.include "../../multimedia/x264-devel/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
