# $NetBSD: Makefile,v 1.10 2012/11/25 23:32:09 othyro Exp $
#

DISTNAME=	busybox-1.3.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.busybox.net/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.busybox.net/
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
