# $NetBSD: Makefile,v 1.1.1.1 2009/10/16 17:40:25 mbowie Exp $
#

MODNAME=		uploadprogress
PECL_VERSION=		1.0.0
CATEGORIES=		devel
MASTER_SITES=		http://pecl.php.net/get/
#EXTRACT_SUFX=		.tar.gz

MAINTAINER=		mbowie@buzmo.com
HOMEPAGE=		http://pecl.php.net/get/
COMMENT=		Provides track progress of a file upload

CONFLICTS=		php-apc-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-${MODNAME}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
