# $NetBSD: Makefile,v 1.1 2013/12/13 00:48:43 noud4 Exp $

DISTNAME=	bfgminer-3.8.0
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
PKGCONFIG_OVERRIDE+=	libblkmaker/libblkmaker_jansson.pc.in

CURSES_DEFAULT=	ncurses
.include "../../mk/curses.buildlink3.mk"

.include "../../devel/libevent/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"

.include "../../textproc/jansson/buildlink3.mk"	# TODO add to pkgsrc
.include "../../wip/uthash/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
