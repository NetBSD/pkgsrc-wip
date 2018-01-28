# $NetBSD: options.mk,v 1.5 2012/06/12 15:46:34 thomasklausner Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.gnunet
PKG_OPTIONS_REQUIRED_GROUPS=	security
PKG_OPTIONS_GROUP.security=	libgcrypt ssl
PKG_SUPPORTED_OPTIONS=		bdb gdbm inet6 tdb
PKG_SUGGESTED_OPTIONS=		inet6

# some sane defaults to use base OS functionality where appropriate
.if !empty(OPSYS:M*BSD)
PKG_SUGGESTED_OPTIONS=	ssl
.else
PKG_SUGGESTED_OPTIONS=	libgcrypt
.endif

.include "../../mk/bsd.options.mk"

# IPv6 doesn't compile in this release
#BUILD_DEFS+=		USE_INET6
#.if !empty(PKG_OPTIONS:inet6)
#CONFIGURE_ARGS+=	--enable-ipv6
#GNUNET_PLIST_ADD+=	lib/libgnunettransport_tcp6.la
#GNUNET_PLIST_ADD+=	lib/libgnunettransport_udp6.la
#.else
CONFIGURE_ARGS+=	--disable-ipv6
#.endif

.if !empty(PKG_OPTIONS:Mbdb)
BDB_ACCEPTED=		db4 db3 db2
.include "../../mk/bdb.buildlink3.mk"
CONFIGURE_ARGS+=	--with-bdb=${BDBBASE}
GNUNET_PLIST_ADD+=	lib/libgnunetafs_database_bdb.la
.else
CONFIGURE_ARGS+=	--without-bdb
.endif

.if !empty(PKG_OPTIONS:Mgdbm)
.include "../../databases/gdbm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gdbm=${BUILDLINK_PREFIX.gdbm}
GNUNET_PLIST_ADD+=	lib/libgnunetafs_database_gdbm.la
.else
CONFIGURE_ARGS+=	--without-gdbm
.endif

.if !empty(PKG_OPTIONS:Mtdb)
.include "../../databases/tdb/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tdb=${BDBBASE}
GNUNET_PLIST_ADD+=	lib/libgnunetafs_database_tdb.la
.else
CONFIGURE_ARGS+=	--without-tdb
.endif

# libgcrypt is used in preference to openssl, per gnunet configure.ac
.if !empty(PKG_OPTIONS:Mlibgcrypt)
.include "../../security/libgcrypt/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libgcrypt-prefix=${BUILDLINK_PREFIX.libgcrypt}
CONFIGURE_ARGS+=	--without-crypto
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-crypto=${BUILDLINK_PREFIX.libgcrypt}
CONFIGURE_ENV+=		LIBGCRYPT_CONFIG=/nonexistent
.endif
