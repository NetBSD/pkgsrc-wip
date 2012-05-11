# $NetBSD: Makefile,v 1.2 2012/05/11 09:38:07 fhajny Exp $

MODNAME=		dtrace
PECL_VERSION=		1.0.3
CATEGORIES+=		devel

MAINTAINER=		filip@joyent.com
COMMENT=		PHP extension for DTrace for Solaris

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		php-dtrace-[0-9]*

MAKE_JOBS_SAFE=		no

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
