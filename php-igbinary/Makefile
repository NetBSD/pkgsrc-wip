# $NetBSD: Makefile,v 1.2 2012/10/05 11:12:56 asau Exp $
#

MODNAME=		igbinary
PECL_VERSION=		1.0.1
CATEGORIES=		devel
MASTER_SITES=		http://opensource.dynamoid.com/
EXTRACT_SUFX=		.tar.gz

MAINTAINER=		mbowie@buzmo.com
HOMEPAGE=		http://opensource.dynamoid.com/
COMMENT=		Binary serialization for PHP

CONFIGURE_ARGS+=	--enable-${MODNAME}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
