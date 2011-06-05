# $NetBSD: options.mk,v 1.2 2011/06/05 17:42:20 gregoire Exp $
#

#
# Description of options (taken from configure --help):
# debug			include memory manager debugging
# freetype		build and install the `grub-mkfont' utility
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.grub2
PKG_SUPPORTED_OPTIONS=	debug freetype
PKG_SUGGESTED_OPTIONS=	freetype

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		freetype

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-mm-debug
.else
CONFIGURE_ARGS+=	--disable-mm-debug
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
CONFIGURE_ARGS+=	--enable-grub-mkfont
PLIST.freetype=		yes
.include "../../graphics/freetype2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-grub-mkfont
.endif
