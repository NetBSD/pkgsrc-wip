# $NetBSD: options.mk,v 1.2 2005/05/31 10:02:09 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.anope
PKG_SUPPORTED_OPTIONS=	mysql unrealircd
PKG_SUGGESTED_OPTIONS=	unrealircd

.include "../../mk/bsd.options.mk"

###
### Use MySQL for storing data
###
.if !empty(PKG_OPTIONS:Mmysql)
.	include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-encryption
.endif

###
### Use UnrealIRCd IRC server
###
.if !empty(PKG_OPTIONS:Munrealircd)
CONFIGURE_ARGS+=	--with-ircd=IRC_UNREAL32
DEPENDS+=		unrealircd>=3.2:../../wip/unrealircd
.endif
