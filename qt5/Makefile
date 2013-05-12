# $NetBSD: Makefile,v 1.6 2013/05/12 13:18:11 othyro Exp $
#

DISTNAME=	qt-everywhere-opensource-src-5.0.2
PKGNAME=	${DISTNAME:S/-everywhere-opensource-src//1}
CATEGORIES=	x11
MASTER_SITES=	http://releases.qt-project.org/qt5/5.0.2/single/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qt-project.org/qt5
COMMENT=	C++ UI framework and foundation for developing applications
LICENSE=	gnu-fdl-v1.3 AND gnu-gpl-v3 AND gnu-lgpl-v2.1

HAS_CONFIGURE=		yes
USE_TOOLS+=		bash perl pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
CONFIG_SHELL=		${PERL5}
CONFIGURE_ARGS+=	-prefix ${PREFIX}/qt5 -opensource -gui -widgets -nis
CONFIGURE_ARGS+=	-confirm-license -largefile -accessibility -no-c++11
CONFIGURE_ARGS+=	-javascript-jit -system-zlib -system-pcre -no-sql-ibase
CONFIGURE_ARGS+=	-optimized-qmake -no-xinput2 -no-sql-oci -v

PKGCONFIG_OVERRIDE+=	qtbase/src/3rdparty/zlib/zlib.pc.in
PKGCONFIG_OVERRIDE+=	qtwebkit/Source/WebKit2/efl/ewebkit2.pc.in
PKGCONFIG_OVERRIDE+=	qtwebkit/Source/WebKit2/webkit2gtk.pc.in
PKGCONFIG_OVERRIDE+=	qtwebkit/Source/JavaScriptCore/javascriptcoregtk.pc.in
PKGCONFIG_OVERRIDE+=	qtwebkit/Source/WebKit/efl/ewebkit.pc.in
PKGCONFIG_OVERRIDE+=	qtwebkit/Source/WebKit/gtk/webkit.pc.in

REPLACE_PERL+=		configure qtbase/bin/syncqt

.include "options.mk"

CONFIGURE_ARGS+=	${CFLAGS:M-I*} ${LDFLAGS:M-L*} ${LDFLAGS:M-l*}
SCRIPTS_ENV+=		HOME=${WRKDIR}

.if !empty(MAKE_JOBS)
CONFIGURE_ENV+=		MAKE_FLAGS=-j${MAKE_JOBS:Q}
.endif

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	-no-kms
.endif

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
