# $NetBSD: options.mk,v 1.1.1.1 2011/09/27 15:13:01 phonohawk Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.hs-blaze-textual

PKG_SUPPORTED_OPTIONS= \
	native

PKG_SUGGESTED_OPTIONS= \
	native

.include "../../mk/bsd.options.mk"

# Use pure Haskell implementation instead of using (currently
# problematic) double-conversion.
.if !empty(PKG_OPTIONS:Mnative)
CONFIGURE_ARGS+=	-fnative
PLIST.native=		yes
.else
CONFIGURE_ARGS+= -f-native
.include "../../wip/hs-double-conversion/buildlink3.mk"
.endif
