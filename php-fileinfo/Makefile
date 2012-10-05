# $NetBSD: Makefile,v 1.3 2012/10/05 11:12:55 asau Exp $

MODNAME=		fileinfo
PECL_VERSION=		1.0.4
CATEGORIES+=		sysutils

MAINTAINER=		filip@joyent.com
COMMENT=		PHP extension for libmagic bindings

PHP_VERSIONS_ACCEPTED=	52
CONFLICTS=		php-fileinfo-[0-9]*

WRKSRC=			${WRKDIR}/Fileinfo-${PECL_VERSION}

CONFIGURE_ARGS+=	--with-fileinfo=${BUILDLINK_PREFIX.php}

.include "../../lang/php/ext.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
