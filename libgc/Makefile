# $NetBSD: Makefile,v 1.1.1.2 2010/11/06 15:07:03 narke_versatile Exp $
#

DISTNAME=	gc-7.1
PKGNAME=    libgc-7.1
CATEGORIES=	lang devel
MASTER_SITES=	http://www.hpl.hp.com/personal/Hans_Boehm/gc/

MAINTAINER=	tcholoka@gmail.com
HOMEPAGE=	http://www.hpl.hp.com/personal/Hans_Boehm/gc/
COMMENT=	Garbage collector library for C and C++
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	bdw-gc.pc.in

.include "../../mk/bsd.pkg.mk"
