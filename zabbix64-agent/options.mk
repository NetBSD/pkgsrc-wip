# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.zabbix64-agent
PKG_SUPPORTED_OPTIONS+=		inet6

.if empty(MISSING_FEATURES:Minet6)
PKG_SUGGESTED_OPTIONS+=		inet6
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
