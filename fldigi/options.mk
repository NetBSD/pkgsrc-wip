# $NetBSD: options.mk,v 1.1 2012/11/04 14:48:43 makoto Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fldigi
PKG_SUPPORTED_OPTIONS=	fltk13
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfltk13)
# With this option, UTF-8 functionalities are fully supported.
.include "../../x11/fltk13/buildlink3.mk"
.else
.include "../../x11/fltk/buildlink3.mk"
# above asks for <1.3, but this version is OK with =1.3
# This means if fltk13 is already installed by some reason,
# this package builds fine with that new version.
BUILDLINK_API_DEPENDS.fltk+=	fltk>=1.1.5rc1
.endif
