# $NetBSD: Makefile,v 1.4 2011/06/28 16:32:11 christtrekker Exp $
#

DISTNAME=	fltk-1.3.0-source
PKGNAME=	${DISTNAME:S/fltk/fltk13/:S/-source//}
WRKSRC=		${WRKDIR}/${DISTNAME:S/-source//}
CATEGORIES=	x11
MASTER_SITES+=	http://ftp.easysw.com/pub/fltk/1.3.0/
MASTER_SITES+=	http://ftp2.easysw.com/pub/fltk/1.3.0/
MASTER_SITES+=	http://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/fltk/1.3.0/

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://fltk.org/
COMMENT=	Fast Light Tool Kit for graphical user interfaces
LICENSE=	gnu-lgpl-v2

CONFLICTS=	fltk-1.[012].*
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

PKG_OPTIONS_VAR=	PKG_OPTIONS.fltk13
PKG_SUPPORTED_OPTIONS=	cairo opengl
PKG_SUGGESTED_OPTIONS=	cairo opengl
PLIST_VARS+=	cairo
PLIST_VARS+=	opengl
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mcairo)
.  include "../../graphics/cairo/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cairo
PLIST.cairo=	yes
.else
CONFIGURE_ARGS+=	--disable-cairo
.endif
.if !empty(PKG_OPTIONS:Mopengl)
.  include "../../graphics/Mesa/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gl
PLIST.opengl=	yes
.else
CONFIGURE_ARGS+=	--disable-gl
.endif
CONFIGURE_ARGS+=	--enable-shared
# Use pkgsrc versions, not package's bundled versions.
CONFIGURE_ARGS+=	--disable-localjpeg --disable-localzlib --disable-localpng

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
