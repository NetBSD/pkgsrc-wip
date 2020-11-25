# $NetBSD: Makefile,v 1.5 2019/09/10 13:26:15 otis Exp $
#

MODNAME=	redis5
PKGMODNAME=	redis
PECL_VERSION=	5.3.2
PECL_DISTNAME=	${PECL_VERSION}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=phpredis/}
GITHUB_PROJECT=	phpredis
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/phpredis/phpredis
COMMENT=	PHP extension for Redis
LICENSE=	php

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PECL_VERSION}

PHP_VERSIONS_ACCEPTED=		72 73 74
PHP_VERSIONS_INCOMPATIBLE=	56

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-error=return-type
.endif

.include "../../textproc/php-json/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
