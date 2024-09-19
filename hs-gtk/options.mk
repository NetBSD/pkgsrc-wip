# $NetBSD: options.mk,v 1.1.1.1 2011/07/12 13:54:38 phonohawk Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.hs-gtk

PKG_SUPPORTED_OPTIONS= \
	gio

PKG_SUGGESTED_OPTIONS= \
	gio

.include "../../mk/bsd.options.mk"

# Depend on GIO package, thereby enabling certain features.
.if !empty(PKG_OPTIONS:Mgio)
CONFIGURE_ARGS+= -fhave-gio
.include "../../wip/hs-gio/buildlink3.mk"
.else
CONFIGURE_ARGS+= -f-have-gio
.endif
