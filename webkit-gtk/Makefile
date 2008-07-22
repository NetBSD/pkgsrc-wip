# $NetBSD: Makefile,v 1.3 2008/07/22 18:43:50 hoka_adam Exp $
#

DISTNAME=	WebKit-r35249
PKGNAME=	${DISTNAME:S/WebKit/webkit-gtk/}
CATEGORIES=	www gtk2
MASTER_SITES=	http://nightly.webkit.org/files/trunk/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://webkit.org/
COMMENT=	gtk2 port of the WebKit browser engine

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	bison gmake perl:build \
		automake autoconf autoheader libtoolize \
		aclocal pkg-config

MAKE_FILE=	GNUmakefile
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-webkit-target=x11 \
			--enable-svg \
			--enable-icon-database \
			--with-http-backend=curl \
			--with-font-backend=freetype

REPLACE_PERL+=	JavaScriptCore/kjs/create_hash_table \
		JavaScriptCore/pcre/dftables \
		SunSpider/make-hosted \
		SunSpider/sunspider \
		SunSpider/sunspider-compare-results \
		WebCore/bindings/scripts/*.pl \
		WebCore/css/*.pl \
		WebCore/dom/*.pl \
		WebCore/platform/text/mac/*.pl \
		WebKit/WebKit.xcodeproj/project.pbxproj \
		WebKit/win/WebKit.vcproj/*.pl \
		WebKitTools/BuildSlaveSupport/build-launcher-app \
		WebKitTools/BuildSlaveSupport/build-launcher-dmg \
		WebKitTools/BuildSlaveSupport/run-performance-tests \
		WebKitTools/Scripts/*

pre-configure:
	cd ${WRKSRC} && ${SHELL} autogen.sh

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
# XXX http backends, soup should be newer to use (reasons to use it?)
.include "../../www/curl/buildlink3.mk"
#.include "../../net/libsoup24/buildlink3.mk"
# Any reason to use pango?
#.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
# NetBSD's flex is not suitable.
.include "../../devel/flex/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
