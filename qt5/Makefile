# $NetBSD: Makefile,v 1.1 2013/03/29 11:25:11 othyro Exp $
#

DISTNAME=	qt-everywhere-opensource-src-5.0.1
PKGNAME=	${DISTNAME:S/-everywhere-opensource-src//1}
CATEGORIES=	x11
MASTER_SITES=	http://releases.qt-project.org/qt5/5.0.1/single/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qt-project.org/qt5
COMMENT=	C++ UI framework and foundation for developing applications
#LICENSE=	# TODO: (see mk/license.mk)

HAS_CONFIGURE=		yes
USE_TOOLS+=		bash perl pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
#CONFIG_SHELL=		${BASH}
CONFIGURE_ARGS+=	-prefix ${WRKSRC}/qtbase -opensource -nomake tests

PKGCONFIG_OVERRIDE+=	qtbase/src/3rdparty/zlib/zlib.pc.in
PKGCONFIG_OVERRIDE+=	qtwebkit/Source/WebKit2/efl/ewebkit2.pc.in
PKGCONFIG_OVERRIDE+=	qtwebkit/Source/WebKit2/webkit2gtk.pc.in
PKGCONFIG_OVERRIDE+=	qtwebkit/Source/JavaScriptCore/javascriptcoregtk.pc.in
PKGCONFIG_OVERRIDE+=	qtwebkit/Source/WebKit/efl/ewebkit.pc.in
PKGCONFIG_OVERRIDE+=	qtwebkit/Source/WebKit/gtk/webkit.pc.in

REPLACE_PERL+=		configure

.include "options.mk"

.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
