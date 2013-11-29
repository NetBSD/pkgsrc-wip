# $NetBSD: Makefile,v 1.1 2013/11/29 21:27:11 thomasklausner Exp $

DISTNAME=	libxshmfence-1.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/archive/individual/lib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Shared memory 'SyncFence' synchronization primitive
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	xshmfence.pc.in

.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
