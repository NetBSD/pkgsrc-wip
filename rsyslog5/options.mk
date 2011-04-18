# $NetBSD: options.mk,v 1.1.1.1 2011/04/18 13:46:22 bartoszkuzma Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rsyslog
PKG_SUPPORTED_OPTIONS=	gnutls gssapi mail mysql pgsql snmp

PLIST_VARS+=		gnutls gssapi mail mysql pgsql snmp

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-gnutls
PLIST.gnutls=			yes
.endif

.if !empty(PKG_OPTIONS:Mgssapi)
.include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=		--enable-gssapi-krb5
PLIST.gssapi=			yes
.endif

.if !empty(PKG_OPTIONS:Mmail)
CONFIGURE_ARGS+=		--enable-mail
PLIST.mail=			yes
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=		--enable-mysql
PLIST.mysql=			yes
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=		--enable-pgsql
PLIST.pgsql=			yes
.endif

.if !empty(PKG_OPTIONS:Msnmp)
.include "../../net/net-snmp/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-snmp
PLIST.snmp=			yes
.endif
