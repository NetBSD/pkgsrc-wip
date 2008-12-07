# $NetBSD: options.mk,v 1.4 2008/12/07 14:16:32 bartoszkuzma Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rsyslog
PKG_SUPPORTED_OPTIONS=	gnutls gssapi largefile mail mysql pgsql snmp
PKG_SUGGESTED_OPTIONS=	largefile

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlargefile)
CONFIGURE_ARGS+=		--enable-largefile
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-gnutls
PLIST_SRC+=			PLIST.gnutls
.endif

.if !empty(PKG_OPTIONS:Mgssapi)
.include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=		--enable-gssapi-krb5
PLIST_SRC+=			PLIST.gssapi
.endif

.if !empty(PKG_OPTIONS:Mmail)
CONFIGURE_ARGS+=		--enable-mail
PLIST_SRC+=			PLIST.mail
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=		--enable-mysql
PLIST_SRC+=			PLIST.mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=		--enable-pgsql
PLIST_SRC+=			PLIST.pgsql
.endif

.if !empty(PKG_OPTIONS:Msnmp)
.include "../../net/net-snmp/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-snmp
PLIST_SRC+=			PLIST.snmp
.endif
