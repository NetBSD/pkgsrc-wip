# $NetBSD: Makefile,v 1.1.1.1 2005/12/02 10:59:14 ghen Exp $

FF_VER=			1.5
PKGNAME=		firefox-${FF_VER}
DISTNAME=		${PKGNAME}-source
CATEGORIES=		www
MASTER_SITES=		http://ftp.mozilla.org/pub/mozilla.org/firefox/releases/${FF_VER}/source/
MASTER_SITES+=		ftp://ftp.mozilla.org/pub/mozilla.org/firefox/releases/${FF_VER}/source/
MASTER_SITES+=		http://public.planetmirror.com.au/pub/firefox/releases/${FF_VER}/source/
MASTER_SITES+=		ftp://public.planetmirror.com.au/pub/firefox/releases/${FF_VER}/source/
MASTER_SITES+=		http://ftp.belnet.be/mirror/ftp.mozilla.org/firefox/releases/${FF_VER}/source/
MASTER_SITES+=		http://ftp.scarlet.be/pub/mozilla.org/firefox/releases/${FF_VER}/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		geert.hendrickx@ua.ac.be
COMMENT=		Standalone web-browser by Mozilla
HOMEPAGE=		http://www.mozilla.com/firefox/

WRKSRC=			${WRKDIR}/mozilla

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-application=browser
CONFIGURE_ARGS+=	--enable-optimize=${CFLAGS:Q}
CONFIGURE_ARGS+=	--with-system-jpeg
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-system-png
CONFIGURE_ARGS+=	--disable-gnomevfs

USE_TOOLS+=		gmake

MAKE_ENV+=		MOZILLA_PKG_NAME=${MOZILLA:Q}

PLIST_SRC=		PLIST.common

.include "options.mk"

PLIST_SRC+=		PLIST.common_end

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
