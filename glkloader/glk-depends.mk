# $NetBSD: glk-depends.mk,v 1.1 2006/07/12 23:18:22 dillo Exp $

.if !empty(PKG_OPTIONS:Mglkloader)
.include "../../wip/glkloader/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mglkterm)
.include "../../wip/glkterm/buildlink3.mk"
.else
.include "../../wip/gtkglk/buildlink3.mk"
.endif
