# $NetBSD: Makefile,v 1.2 2010/06/13 22:47:10 thomasklausner Exp $
#

DISTNAME=	libharu-2.1.0
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://libharu.org/files/

MAINTAINER=	emil@math.su.se
HOMEPAGE=	http://libharu.org/files/
COMMENT=	Library for generating PDF files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.libharu
PKG_SUPPORTED_OPTIONS=	png zlib
PKG_SUGGESTED_OPTIONS=	png zlib

.include "../../mk/bsd.options.mk"

# Package-specific option-handling

.if !empty(PKG_OPTIONS:Mpng)
CONFIGURE_ARGS+=	--with-png=${BUILDLINK_PREFIX.png}
.endif

.if !empty(PKG_OPTIONS:Mzlib)
CONFIGURE_ARGS+=	--with-zlib
.endif


.if !empty(PKG_OPTIONS:Mzlib)
.include "../../devel/zlib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
