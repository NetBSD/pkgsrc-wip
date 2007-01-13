# $NetBSD: Makefile,v 1.6 2007/01/13 10:36:20 rillig Exp $
#

DISTNAME=	busybox-1.3.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.busybox.net/downloads/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.busybox.net/
COMMENT=	The Swiss Army Knife of Embedded Linux

OPSYSVARS+=	HOSTLDFLAGS
HOSTLDFLAGS.NetBSD=	-lintl

USE_TOOLS+=	gmake
MAKE_ENV+=	HOSTLDFLAGS=${HOSTLDFLAGS:Q}

CHECK_PORTABILITY_SKIP+=	scripts/individual
CHECK_PORTABILITY_SKIP+=	scripts/kconfig/lxdialog/check-lxdialog.sh

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${MAKE_ENV} make defconfig

.include "../../mk/bsd.pkg.mk"
