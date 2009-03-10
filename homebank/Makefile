# $NetBSD: Makefile,v 1.1.1.1 2009/03/10 14:33:51 jihbed Exp $
#

DISTNAME=	homebank-4.0.2
CATEGORIES=	finance
MASTER_SITES=	http://homebank.free.fr/public/

MAINTAINER=	kamel.derouihe@gmail.com
HOMEPAGE=	http://homebank.free.fr/public/
COMMENT=	HomeBank is to manage your personal accounts at home

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=	xdg-1.4
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config perl intltool gmake msgfmt

PKG_OPTIONS_VAR=                PKG_OPTIONS.homebank
PKG_SUPPORTED_OPTIONS=          libofx
PKG_SUGGESTED_OPTIONS=          libofx

.include "../../mk/bsd.options.mk"

.if !empty (PKG_OPTIONS:Mlibofx)
.include "../../finance/libofx/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libofx
.else
CONFIGURE_ARGS+=	--without-libofx
.endif


.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
