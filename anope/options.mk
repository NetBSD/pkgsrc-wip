# $NetBSD: options.mk,v 1.5 2006/01/02 17:14:09 adrian_p Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.anope
PKG_SUPPORTED_OPTIONS=	mysql dbencryption

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
.if !empty(PKG_OPTIONS:Mmysql) && !empty(PKG_OPTIONS:Mdbencryption)
CONFIGURE_ARGS+=	--with-encryption
.endif
