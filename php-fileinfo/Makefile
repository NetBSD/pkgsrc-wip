# $NetBSD: Makefile,v 1.1.1.1 2009/10/08 10:55:27 fhajny Exp $

MODNAME=		fileinfo
PECL_VERSION=		1.0.4
CATEGORIES+=		sysutils

MAINTAINER=		filip@joyent.com
COMMENT=		PHP extension for libmagic bindings

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		php-fileinfo-[0-9]*

WRKSRC=			${WRKDIR}/Fileinfo-${PECL_VERSION}

CONFIGURE_ARGS+=	--with-fileinfo=${BUILDLINK_PREFIX.php}

.include "../../lang/php/ext.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
