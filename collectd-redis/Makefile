# $NetBSD: Makefile,v 1.1 2014/02/17 11:21:55 fhajny Exp $

COLLECTD_PACKAGE=	redis
COLLECTD_PLUGINS=	redis

USE_TOOLS+=     gmake
USE_LIBTOOL=    yes
MAKE_ENV+=      DESTDIR=${DESTDIR}

COMMENT=		Statistics collection daemon - redis plugins

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libhires=${BUILDLINK_PREFIX.hiredis}

.include "../../databases/hiredis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
