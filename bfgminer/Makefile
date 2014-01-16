# $NetBSD: Makefile,v 1.4 2014/01/16 13:19:58 nsloss Exp $

DISTNAME=	bfgminer-3.9.0
PKGREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	http://luke.dashjr.org/programs/bitcoin/files/bfgminer/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.zip

MAINTAINER=	noud4@home.nl
HOMEPAGE=	http://bfgminer.org/
COMMENT=	Modular ASIC/FPGA Bitcoin miner
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--enable-cpumining
CONFIGURE_ARGS+=	--enable-scrypt
PKGCONFIG_OVERRIDE+=	libblkmaker/libblkmaker_jansson.pc.in

CURSES_DEFAULT=	ncurses
.include "../../mk/curses.buildlink3.mk"

.include "../../devel/libevent/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"

.include "../../textproc/jansson/buildlink3.mk"
.include "../../wip/uthash/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
