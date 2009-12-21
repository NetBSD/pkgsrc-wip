# $NetBSD: options.mk,v 1.1.1.1 2009/12/21 17:41:00 gregoire Exp $
#

#
# Description of options (taken from configure --help):
# grub-mm-debug		include memory manager debugging
# grub-mkfont		build and install the `grub-mkfont' utility
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.grub2
PKG_SUPPORTED_OPTIONS=	grub-mm-debug grub-mkfont
PKG_SUGGESTED_OPTIONS=	grub-mm-debug grub-mkfont

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		mkfont

.if !empty(PKG_OPTIONS:Mgrub-mm-debug)
CONFIGURE_ARGS+=	--enable-mm-debug
.else
CONFIGURE_ARGS+=	--disable-mm-debug
.endif

.if !empty(PKG_OPTIONS:Mgrub-mkfont)
CONFIGURE_ARGS+=	--enable-grub-mkfont
PLIST.mkfont=		yes
.include "../../graphics/freetype2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-grub-mkfont
.endif
