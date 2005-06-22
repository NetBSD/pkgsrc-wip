# $NetBSD: hacks.mk,v 1.1.1.1 2005/06/22 15:06:14 tvierling Exp $

.include "../../mk/compiler.mk"

# Avoid an ICE in gcc2 on sparc64
.if !empty(CC_VERSION:Mgcc-*)
PKG_HACKS+=		sparc64-gcc2-ice
CONFIGURE_ENV+=		F77=${FALSE}
.endif
