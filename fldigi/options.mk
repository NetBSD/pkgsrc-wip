# $NetBSD: options.mk,v 1.3 2012/11/15 22:23:06 lexort Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fldigi
PKG_SUPPORTED_OPTIONS=	fltk11
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# Force building with requested version.
.if !empty(PKG_OPTIONS:Mfltk11)
# fltk11 option: use unmaintained version 1.1
.include "../../x11/fltk/buildlink3.mk"
.else
# NOT fltk11 option: use version 1.3
# With this option, UTF-8 functionalities are fully supported.
.include "../../x11/fltk13/buildlink3.mk"
.endif
