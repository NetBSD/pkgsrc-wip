# $NetBSD: options.mk,v 1.1.1.1 2008/08/28 21:34:40 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.digikam
PKG_SUPPORTED_OPTIONS=	pim # libmarblewidget liblensfun

# XXX: package the two other optional dependencies

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpim)
.include "../../wip/kdepimlibs4/buildlink3.mk"
.endif
