# $NetBSD: options.mk,v 1.1.1.1 2004/11/17 16:19:13 adrian_p Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.anope
PKG_SUPPORTED_OPTIONS=	mysql unrealircd

.if !defined(PKG_OPTIONS.anope)
PKG_DEFAULT_OPTIONS+=	unrealircd
.endif

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
