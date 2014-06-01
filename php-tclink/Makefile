# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:38 thomasklausner Exp $
#

MODNAME=		tclink
PECL_DISTNAME=		${MODNAME}-${PECL_VERSION}-php
PECL_VERSION=		4.0.2
CATEGORIES=		finance
MASTER_SITES=		https://vault.trustcommerce.com/downloads/
EXTRACT_SUFX=		.tar.gz

MAINTAINER=		mbowie@buzmo.com
HOMEPAGE=		http://www.trustcommerce.com/
COMMENT=		PHP extension for TrustCommerce credit card processing

CONFIGURE_ARGS=         --enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
