# $NetBSD: Makefile,v 1.2 2012/10/05 11:12:56 asau Exp $
#

MODNAME=		tclink
PECL_DISTNAME=		${MODNAME}-${PECL_VERSION}-php
PECL_VERSION=		3.4.4
CATEGORIES=		finance
MASTER_SITES=		http://www.trustcommerce.com/downloads/
EXTRACT_SUFX=		.tar.gz

MAINTAINER=		mbowie@buzmo.com
HOMEPAGE=		http://www.trustcommerce.com/
COMMENT=		PHP extension for TrustCommerce credit card processing

CONFIGURE_ARGS=         --enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
