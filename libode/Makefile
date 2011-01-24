# $NetBSD: Makefile,v 1.1.1.1 2011/01/24 09:40:28 jihbed Exp $
#

DISTNAME=	ode-0.11.1
PKGNAME= 	lib${DISTNAME}
CATEGORIES=	science
MASTER_SITES=	http://garr.dl.sourceforge.net/project/opende/ODE/0.11.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.ode.org/
COMMENT=	Open Dynamics Engine
LICENSE=	gnu-lgpl-v2.1 AND modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64 Linux-*-*

CONFIGURE_ARGS+=	--enable-double-precision

PKGCONFIG_OVERRIDE+=	ode.pc.in

.include "../../mk/bsd.pkg.mk"
