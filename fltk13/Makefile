# $NetBSD: Makefile,v 1.2 2010/10/05 22:02:43 christtrekker Exp $
#

DISTNAME=	fltk-1.3.x-r7709
PKGNAME=	${DISTNAME:S/fltk/fltk13/:S/x-r/pre/}
CATEGORIES=	x11
MASTER_SITES+=	http://ftp.easysw.com/pub/fltk/snapshots/
MASTER_SITES+=	http://ftp2.easysw.com/pub/fltk/snapshots/
MASTER_SITES+=	http://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/fltk/snapshots/

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
.endif
.if !empty(PKG_OPTIONS:Mopengl)
.  include "../../graphics/Mesa/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gl
PLIST.opengl=	yes
.endif
CONFIGURE_ARGS+=	--enable-shared

.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
