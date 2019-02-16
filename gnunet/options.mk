# $NetBSD$
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.gnunet
PKG_SUPPORTED_OPTIONS=		bdb gdbm inet6 tdb doc mdoc ssl libgcrypt idn
PKG_SUGGESTED_OPTIONS=		inet6 doc ssl libgcrypt

# openssl is currently required by:
# src/transport/gnunet-transport-certificate-creation
# src/gns/gnunet-gns-proxy-setup-ca

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
.endif

.if !empty(PKG_OPTIONS:Mdoc)
CONFIGURE_ARGS+=	--enable-documentation
.else
CONFIGURE_ARGS+=	--disable-documentation
.endif

# build the mdoc output.
.if !empty(PKG_OPTIONS:Mmdoc)
BUILD_DEPENDS+=		texi2mdoc-[0-9]*:../../textproc/texi2mdoc
CONFIGURE_ARGS+=	--enable-texi2mdoc-generation
.else
CONFIGURE_ARGS+=	--disable-texi2mdoc-generation
.endif

.if !empty(PKG_OPTIONS:Midn)
.include "../../devel/libidn2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn2=${BUILDLINK_PREFIX.libidn2}
.else
.include "../../devel/libidn/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn=${BUILDLINK_PREFIX.libidn}
.endif
