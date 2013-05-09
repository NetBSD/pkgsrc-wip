# $NetBSD: Makefile,v 1.4 2013/05/09 17:36:32 othyro Exp $
#

DISTNAME=	qt-everywhere-opensource-src-5.0.2
PKGNAME=	${DISTNAME:S/-everywhere-opensource-src//1}
CATEGORIES=	x11
MASTER_SITES=	http://releases.qt-project.org/qt5/5.0.2/single/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qt-project.org/qt5
COMMENT=	C++ UI framework and foundation for developing applications
LICENSE=	gnu-fdl-v1.3 AND gnu-gpl-v3 AND gnu-gpl-v2.1
		# XXX AND license-preview commercial ?

HAS_CONFIGURE=		yes
USE_TOOLS+=		bash perl pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
CONFIG_SHELL=		${PERL5}
CONFIGURE_ARGS+=	-prefix ${WRKSRC}/qtbase -opensource -nomake tests
CONFIGURE_ARGS+=	-confirm-license

PKGCONFIG_OVERRIDE+=	qtbase/src/3rdparty/zlib/zlib.pc.in
PKGCONFIG_OVERRIDE+=	qtwebkit/Source/WebKit2/efl/ewebkit2.pc.in
PKGCONFIG_OVERRIDE+=	qtwebkit/Source/WebKit2/webkit2gtk.pc.in
PKGCONFIG_OVERRIDE+=	qtwebkit/Source/JavaScriptCore/javascriptcoregtk.pc.in
PKGCONFIG_OVERRIDE+=	qtwebkit/Source/WebKit/efl/ewebkit.pc.in
PKGCONFIG_OVERRIDE+=	qtwebkit/Source/WebKit/gtk/webkit.pc.in

REPLACE_PERL+=		configure qtbase/bin/syncqt

.include "options.mk"

.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/xcb-util-renderutil/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
