# $NetBSD: Makefile,v 1.3 2009/08/02 21:59:35 pettai Exp $

DISTNAME=	Botan-1.8.5
PKGNAME=	botan-1.8.5
#PKGREVISION=	0
CATEGORIES=	security
MASTER_SITES=	http://files.randombit.net/botan/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://botan.randombit.net/
COMMENT=	Portable, easy to use, and efficient C++ crypto library
LICENSE=	botan-license

LICENSE_FILE=	${FILESDIR}/botan-license

USE_TOOLS+=	perl

USE_LANGUAGES=	c++
REPLACE_PERL=	./configure.pl
#REPLACE_PYTHON=	./configure.py
#HAS_CONFIGURE=	yes
CONFIG_SHELL=		perl
#CONFIGURE_SCRIPT=	./configure.pl
#CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

MAKE_FLAGS+=	LIB_OPT=${CXXFLAGS:Q}

CXXFLAGS.DragonFly+=	-D_DRAGONFLY_SOURCE
#CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE
BUILDLINK_TRANSFORM+=	rm:-mcpu=i686

# depricated
pre-build:
	cd ${WRKSRC} && \
	${CONFIG_SHELL} ./configure.pl --prefix=${PREFIX:Q}

# new way
#pre-build:
#	cd ${WRKSRC} && \
#	${CONFIG_SHELL} ./configure.py --prefix=${PREFIX:Q}

.include "../../mk/bsd.pkg.mk"
