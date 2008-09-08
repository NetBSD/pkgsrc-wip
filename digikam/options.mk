# $NetBSD: options.mk,v 1.2 2008/09/08 14:56:32 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.digikam
PKG_SUPPORTED_OPTIONS=	lensfun marble pim
PKG_SUGGESTED_OPTIONS=	lensfun marble pim

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlensfun)
.include "../../wip/lensfun/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmarble)
.include "../../wip/kdeedu4/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpim)
.include "../../wip/kdepimlibs4/buildlink3.mk"
.endif
