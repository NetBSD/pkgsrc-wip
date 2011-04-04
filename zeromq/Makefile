# $NetBSD: Makefile,v 1.1.1.1 2011/04/04 14:00:46 obache Exp $
#

DISTNAME=	zeromq-2.0.11
CATEGORIES=	devel
MASTER_SITES=	http://download.zeromq.org/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://download.zeromq.org/
COMMENT=	The ZeroMQ messaging library
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	src/libzmq.pc.in

.include "../../mk/bsd.pkg.mk"
