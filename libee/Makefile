# $NetBSD: Makefile,v 1.7 2012/10/03 09:10:38 asau Exp $
#

DISTNAME=		libee-0.4.1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.libee.org/files/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.libee.org/
COMMENT=		Event Expression Library inspired by CEE
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-testbench

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
USE_TOOLS+=		bash pkg-config
USE_MULTIARCH=		lib

PKGCONFIG_OVERRIDE+=	libee.pc.in

.include "../../devel/libestr/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
