# $NetBSD: Makefile,v 1.1 2013/01/03 03:38:48 othyro Exp $
#

DISTNAME=	libxs-1.2.0
PKGNAME=	crossroads-io-1.2.0
CATEGORIES=	devel
MASTER_SITES=	http://download.crossroads.io/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.crossroads.io/
COMMENT=	Fork of ZeroMQ, high-performance asynchronous messaging library
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	src/libzmq.pc.in
PKGCONFIG_OVERRIDE+=	src/libxs.pc.in

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
