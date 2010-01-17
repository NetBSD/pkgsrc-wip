# $NetBSD: Makefile,v 1.2 2010/01/17 12:03:30 thomasklausner Exp $

MODNAME=		http
PKGREVISION=		1
PECL_VERSION=		1.6.5
CATEGORIES+=		www

PECL_DISTNAME=		pecl_http-${PECL_VERSION}

MAINTAINER=		filip@joyent.com
COMMENT=		PHP extension for extended HTTP support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		php-http-[0-9]*

CONFIGURE_ARGS+=	--with-http-curl-requests=${BUILDLINK_PREFIX.curl}
CONFIGURE_ARGS+=	--with-http-curl-libevent=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=	--with-http-magic-mime=${BUILDLINK_PREFIX.file}
CONFIGURE_ARGS+=	--with-http-zlib-compression=${BUILDLINK_PREFIX.zlib}

.include "../../lang/php/ext.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
