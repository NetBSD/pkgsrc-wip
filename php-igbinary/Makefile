# $NetBSD: Makefile,v 1.1.1.1 2009/10/06 19:40:25 mbowie Exp $
#

MODNAME=		igbinary
PECL_VERSION=		1.0.1
CATEGORIES=		devel
MASTER_SITES=		http://opensource.dynamoid.com/
EXTRACT_SUFX=		.tar.gz

MAINTAINER=		mbowie@buzmo.com
HOMEPAGE=		http://opensource.dynamoid.com/
COMMENT=		Binary serialization for PHP

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-${MODNAME}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
