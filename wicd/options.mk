# $NetBSD: options.mk,v 1.1.1.1 2011/01/05 13:23:14 rubengonzalez Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wicd
PKG_SUPPORTED_OPTIONS=	dhcpcd net-tools wireless-tools
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdhcpcd)
DEPENDS+=	dhcpcd>=5.2.7:../../net/dhcpcd
.endif

.if !empty(PKG_OPTIONS:Mnet-tools)
DEPENDS+=	net-tools>=1.60:../../wip/net-tools
.endif

.if !empty(PKG_OPTIONS:Mwireless-tools)
DEPENDS+=	wireless-tools>=27:../../wip/wireless-tools
.endif
