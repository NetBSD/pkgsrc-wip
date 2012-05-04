# $NetBSD: Makefile,v 1.6 2012/05/04 07:48:31 bartoszkuzma Exp $
#

DISTNAME=		libee-0.4.1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.libee.org/files/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.libee.org/
COMMENT=		Event Expression Library inspired by CEE
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-testbench

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
USE_TOOLS+=		bash pkg-config

PKGCONFIG_OVERRIDE+=	libee.pc.in

.include "../../wip/libestr/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
