# $NetBSD: Makefile,v 1.3 2010/09/17 12:01:44 fhajny Exp $
#

MODNAME=		memcached
PECL_VERSION=		1.0.2
CATEGORIES+=		devel

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://github.com/andreiz/php-memcached
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
