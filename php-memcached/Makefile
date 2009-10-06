# $NetBSD: Makefile,v 1.1.1.2 2009/10/06 09:16:58 fhajny Exp $
#

MODNAME=		memcached
PECL_VERSION=		1.0.0
CATEGORIES+=		devel
COMMENT=		PHP extension for interfacing with memcached via libmemcached library

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		php-memcached-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-libmemcached-dir=${PREFIX}
WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "../../wip/libmemcached/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
