# $NetBSD: Makefile,v 1.3 2012/02/12 18:32:21 bartoszkuzma Exp $
#

DISTNAME=		libee-0.3.2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.libee.org/files/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.libee.org/
COMMENT=		Event Expression Library inspired by CEE
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-testbench

USE_LIBTOOL=		yes
USE_TOOLS+=		bash pkg-config

PKGCONFIG_OVERRIDE+=	libee.pc.in

do-build:
	cd ${WRKSRC} && ${MAKE}

.include "../../wip/libestr/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
