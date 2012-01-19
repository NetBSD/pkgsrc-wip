# $NetBSD: options.mk,v 1.1 2012/01/19 13:31:22 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libgda
PKG_SUPPORTED_OPTIONS=	fam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfam)
.  include "../../mk/fam.buildlink3.mk"
.endif
