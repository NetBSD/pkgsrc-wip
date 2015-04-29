# $NetBSD: Makefile,v 1.2 2015/04/29 13:13:34 tnn2 Exp $

DISTNAME=	libxshmfence-1.2
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

# Needs additional pthread functions or alternative syncronization
# implemenation on NetBSD. See PR lib/49529.

ONLY_FOR_PLATFORM+=	Linux-*-* FreeBSD-*-*

.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
