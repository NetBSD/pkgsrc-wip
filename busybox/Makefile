# $NetBSD: Makefile,v 1.9 2012/09/24 17:14:43 asau Exp $
#

DISTNAME=	busybox-1.3.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.busybox.net/downloads/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.busybox.net/
COMMENT=	The Swiss Army Knife of Embedded Linux
LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	Linux-*-*
# See crunchgen(1) on BSD-systems for similar functionality.

USE_TOOLS+=	gmake

CHECK_PORTABILITY_SKIP+=	scripts/individual
CHECK_PORTABILITY_SKIP+=	scripts/kconfig/lxdialog/check-lxdialog.sh

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${MAKE_ENV} make defconfig

.include "../../mk/bsd.pkg.mk"
