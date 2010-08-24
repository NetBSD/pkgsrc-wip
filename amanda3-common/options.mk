# $NetBSD: options.mk,v 1.1.1.1 2010/08/24 02:40:36 schnoebe Exp $

# Since amanda's ipv6 usage is broken, turn it off by default.

PKG_OPTIONS_VAR=	PKG_OPTIONS.amanda
PKG_SUPPORTED_OPTIONS=	inet6 ssh fqdn readline smbclient dump-snap

.include "../../mk/bsd.options.mk"

PKG_OPTIONS_LEGACY_VARS+=	AMANDA_FQDN:fqdn
PKG_OPTIONS_LEGACY_VARS+=	AMANDA_SSH:ssh
PKG_OPTIONS_LEGACY_VARS+=	AMANDA_SMB:smbclient
PKG_OPTIONS_LEGACY_VARS+=	AMANDA_DUMP_SNAP:dump-snap

PKG_OPTIONS_LEGACY_VARS+=	USE_INET6:inet6

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif

.if !empty(PKG_OPTIONS:Mfqdn)
CONFIGURE_ARGS+=	--with-fqdn
.else
CONFIGURE_ARGS+=	--without-fqdn
.endif

.if !empty(PKG_OPTIONS:Mssh)
CONFIGURE_ARGS+=	--with-ssh-security
.else
CONFIGURE_ARGS+=	--without-ssh-security
.endif

.if !empty(PKG_OPTIONS:Mreadline)
CONFIGURE_ARGS+=	--with-readline
.include "../../devel/readline/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-readline
.endif

.if !empty(PKG_OPTIONS:Msmbclient)
CONFIGURE_ARGS+=	--with-smbclient
DEPENDS+=		samba>=2.0:../../net/samba
.else
CONFIGURE_ARGS+=	--without-smbclient
.endif

.if !empty(PKG_OPTIONS:Mdump-snap)
CONFIGURE_ARGS+=	--with-dump-use-snapshot
CONFIGURE_ARGS+=	--with-rundump
.endif
