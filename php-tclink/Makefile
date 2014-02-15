# $NetBSD: Makefile,v 1.3 2014/02/15 01:50:19 mbowie Exp $
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

FETCH_USING=		curl
CONFIGURE_ARGS=         --enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
