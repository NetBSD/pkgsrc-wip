# $NetBSD: options.mk,v 1.1 2007/11/20 05:56:10 bsadewitz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.grub2
PKG_SUPPORTED_OPTIONS=	grub-mm-debug grub-emu

### New options descriptions:
### grub-emu		Include memory manager debugging
### grub-mm-debug	Build and install the `grub-emu' debugging utility
###
PKG_SUGGESTED_OPTIONS=	grub-mm-debug grub-emu

.include "../../mk/bsd.options.mk"
###
### Include memory manager debugging
###
.if !empty(PKG_OPTIONS:Mgrub-mm-debug)
CONFIGURE_ARGS+=	--enable-mm-debug
.endif
###
### Build and install the `grub-emu' debugging utility
###
.if !empty(PKG_OPTIONS:Mgrub-emu)
CONFIGURE_ARGS+=	--enable-grub-emu
PLIST_SRC+=		${PKGDIR}/PLIST.grub-emu
.  include "../../mk/curses.buildlink3.mk" # XXXbjs make sure this is OK
.endif
