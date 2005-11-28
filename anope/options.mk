# $NetBSD: options.mk,v 1.3 2005/11/28 23:12:39 adrian_p Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.anope 
PKG_SUPPORTED_OPTIONS=	mysql unrealircd ircd-hybrid db-encryption

.include "../../mk/bsd.options.mk"

###
### Use MySQL for storing data
###
.if !empty(PKG_OPTIONS:Mmysql)
.	include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

###
### Encrypt sensitive data in the database (only with mysql)
###
.if !empty(PKG_OPTIONS:Mmysql) && !empty(PKG_OPTIONS:Mdb-encryption)
CONFIGURE_ARGS+=	--with-encryption
.endif

###
### Use UnrealIRCd IRC server
###
.if !empty(PKG_OPTIONS:Munrealircd)
DEPENDS+=		unrealircd>=3.1:../../wip/unrealircd
.endif

###
### Use ircd-hybrid IRC server
###
.if !empty(PKG_OPTIONS:Mircd-hybrid)
DEPENDS+=		ircd-hybrid>=7.0:../../chat/ircd-hybrid
.endif
