# $NetBSD: Makefile,v 1.3 2007/02/14 12:58:22 netcap Exp $
#

DISTNAME=		audacious-1.2.2
CATEGORIES=		audio
MASTER_SITES=		http://audacious-media-player.org/release/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jfranz@bsdprojects.net
HOMEPAGE=		http://audacious-media-player.org/
COMMENT=        	Media player based on BMP and XMMS

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool pkg-config
USE_LIBTOOL=    	yes
USE_LANGUAGES+= 	c c++

CONFIGURE_ARGS+=        --enable-chardet --enable-nls

PKGCONFIG_OVERRIDE+=	audacious.pc.in

PKG_OPTIONS_VAR=        PKG_OPTIONS.audacious
PKG_SUPPORTED_OPTIONS=  gnome inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=        --enable-gconf
CONFIGURE_ARGS+=        --enable-gnome-vfs
.       include "../../devel/GConf2/buildlink3.mk"
.       include "../../sysutils/gnome-vfs2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=        --enable-ipv6
.endif

.include "../../devel/pango/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
