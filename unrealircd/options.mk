# $NetBSD: options.mk,v 1.6 2005/01/10 20:37:06 adrian_p Exp $

.if defined(USE_SSL) && !empty(USE_SSL:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	ssl
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.unrealircd
PKG_SUPPORTED_OPTIONS=	inet6 nospoof hub leaf ziplinks remoteinc ssl chroot

.if !defined(PKG_OPTIONS.unrealircd)
PKG_DEFAULT_OPTIONS+=	hub
.endif

.include "../../mk/bsd.options.mk"

###
### Can't be both a leaf and a hub IRC server
###
.if !empty(PKG_OPTIONS:Mhub) && !empty(PKG_OPTIONS:Mleaf)
PKG_FAIL_REASON+=	"The server cannot be both a hub and a leaf." \
			"Please change ${PKG_OPTIONS_VAR} to one or the other."
.endif

###
### Enable IPv6 support 
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-inet6
.endif

###
### Enable SSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.	include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ssl=${SSLBASE}
.endif

###
### Enable Anti-Spoofing protection for older OS's with an insecure IPv4 stack
###
.if !empty(PKG_OPTIONS:Mnospoof)
CONFIGURE_ARGS+=	--enable-nospoof
.endif

###
### Compile as a hub or leaf server
###
.if !empty(PKG_OPTIONS:Mhub)
CONFIGURE_ARGS+=	--enable-hub
.	elif !empty(PKG_OPTIONS:Mleaf)
	CONFIGURE_ARGS+=	--enable-leaf
.endif

###
### Compile in support for ziplinks.  This compresses data sent from
### server <-> server with zlib.
###
.if !empty(PKG_OPTIONS:Mziplinks)
CONFIGURE_ARGS+=		--enable-ziplinks
.	include "../../devel/zlib/buildlink3.mk"
.endif

###
### Compile in support for remote include files.
###
.if !empty(PKG_OPTIONS:Mremoteinc)
CONFIGURE_ARGS+=		--enable-libcurl
.	include "../../www/curl/buildlink3.mk"
.	include "../../wip/c-ares/buildlink3.mk"
.endif

###
### Compile in CHROOTDIR support. 
### As far as pkgsrc goes this is just an expirement.  You should read the 
### unrealircd docs/source for further information on this.  By default 
### CHROOTDIR is defined as ${IRCD_HOME}.
###
.if !empty(PKG_OPTIONS:Mchroot)
CFLAGS+=	-DCHROOTDIR
.endif
