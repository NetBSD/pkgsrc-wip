# $NetBSD: Makefile,v 1.4 2012/11/14 00:16:11 othyro Exp $
#

DISTNAME=	ode-0.11.1
PKGNAME=	lib${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opende/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.ode.org/
COMMENT=	Open Dynamics Engine
LICENSE=	gnu-lgpl-v2.1 AND modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64 Linux-*-*

CONFIGURE_ARGS+=	--enable-double-precision

PKGCONFIG_OVERRIDE+=	ode.pc.in

.include "../../mk/bsd.pkg.mk"
