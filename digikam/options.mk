# $NetBSD: options.mk,v 1.3 2009/08/16 12:22:31 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.digikam
PKG_SUPPORTED_OPTIONS=	lensfun liblqr marble pim
PKG_SUGGESTED_OPTIONS=	lensfun liblqr marble pim

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlensfun)
.include "../../graphics/lensfun/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mliblqr)
.include "../../graphics/liblqr/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmarble)
.include "../../wip/kdeedu4/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpim)
.include "../../wip/kdepimlibs4/buildlink3.mk"
.endif
