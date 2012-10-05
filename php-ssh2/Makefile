# $NetBSD: Makefile,v 1.2 2012/10/05 11:12:56 asau Exp $
#

MODNAME=		ssh2
PECL_VERSION=		0.11.3
CATEGORIES+=		security

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://www.libssh2.org/
COMMENT=		PHP bindings to the functions of libssh2
LICENSE=		php

CONFLICTS=		php-ssh2-[0-9]*

CONFIGURE_ARGS+=	--with-ssh2=${PREFIX}
WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "../../security/libssh2/buildlink3.mk"
.include "../../lang/php/ext.mk"
#.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
