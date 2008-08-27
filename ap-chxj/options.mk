# $NetBSD: options.mk,v 1.1 2008/08/27 05:04:40 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ap-chxj
PKG_SUPPORTED_OPTIONS=	mysql memcached

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-mysql-cookie
CONFIGURE_ARGS+=	--with-mysql-header=${BUILDLINK_PREFIX.mysql-client}/include/mysql
CONFIGURE_ARGS+=	--with-mysql-lib-dir=${BUILDLINK_PREFIX.mysql-client}/lib
.endif

.if !empty(PKG_OPTIONS:Mmemcached)
.include "../../devel/libmemcache/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-memcached-cookie
CONFIGURE_ARGS+=	--with-memcached-header=${BUILDLINK_PREFIX.libmemcache}/include
CONFIGURE_ARGS+=	--with-memcached-lib-dir=${BUILDLINK_PREFIX.libmemcache}/lib
.endif
