# $NetBSD: Makefile,v 1.4 2012/10/05 11:12:55 asau Exp $

MODNAME=		dtrace
PECL_VERSION=		1.0.3
CATEGORIES+=		devel

MAINTAINER=		filip@joyent.com
COMMENT=		PHP extension for DTrace for Solaris

CONFLICTS=		php-dtrace-[0-9]*

PHP_VERSIONS_ACCEPTED=	53

MAKE_JOBS_SAFE=		no

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
