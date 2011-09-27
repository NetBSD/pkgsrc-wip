# $NetBSD: options.mk,v 1.2 2011/09/27 15:20:07 phonohawk Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.hs-blaze-textual

PKG_SUPPORTED_OPTIONS= \
	native

PKG_SUGGESTED_OPTIONS= \
	native

.include "../../mk/bsd.options.mk"

# Use pure Haskell implementation instead of (currently problematic)
# double-conversion package. See:
# http://hackage.haskell.org/trac/ghc/ticket/5386
# http://hackage.haskell.org/trac/ghc/ticket/5435
.if !empty(PKG_OPTIONS:Mnative)
CONFIGURE_ARGS+=	-fnative
PLIST.native=		yes
.else
CONFIGURE_ARGS+= -f-native
.include "../../wip/hs-double-conversion/buildlink3.mk"
.endif
