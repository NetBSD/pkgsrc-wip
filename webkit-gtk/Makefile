# $NetBSD: Makefile,v 1.1.1.1 2008/05/01 18:04:02 hoka_adam Exp $
#

DISTNAME=	WebKit-r32698
#DISTNAME=	WebKit-r30549 # FreeBSD's version
CATEGORIES=	www gtk2
MASTER_SITES=	http://nightly.webkit.org/files/trunk/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://webkit.org/
COMMENT=	gtk2 port of the WebKit browser engine

# remove if you can construct a PLIST, please.
BROKEN=		I couldn't build this yet so it lack PLIST,\
		but remove this line and try if you can\
		and report success or failure. :)

USE_LANGUAGES=	c c++
USE_TOOLS+=	libtool flex bison gmake perl:build \
		automake autoconf autoheader libtoolize aclocal

MAKE_FILE=	GNUmakefile
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-webkit-target=x11 \
			--enable-svg \
			--enable-icon-database

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
# XXX http backends, optionise this (?)
#.include "../../www/curl/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
#
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
