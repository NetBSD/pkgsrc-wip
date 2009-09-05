# $NetBSD: Makefile,v 1.4 2009/09/05 18:46:29 asau Exp $

DISTNAME=	Botan-1.8.6
PKGNAME=	botan-1.8.6
CATEGORIES=	security
MASTER_SITES=	http://files.randombit.net/botan/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://botan.randombit.net/
COMMENT=	Portable, easy to use, and efficient C++ crypto library
LICENSE=	botan-license

LICENSE_FILE=	${FILESDIR}/botan-license

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	./configure.py
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
USE_TOOLS=		pkg-config

USE_LANGUAGES=		c++

MAKE_FLAGS+=		LIB_OPT=${CXXFLAGS:Q}

CXXFLAGS.DragonFly+=	-D_DRAGONFLY_SOURCE
#CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE
BUILDLINK_TRANSFORM+=	rm:-mcpu=i686

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
