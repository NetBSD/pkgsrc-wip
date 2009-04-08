# $NetBSD: Makefile,v 1.1.1.1 2009/04/08 07:44:51 pettai Exp $

DISTNAME=	Botan-1.8.1
PKGNAME=	botan-1.8.1
#PKGREVISION=	0
CATEGORIES=	security
MASTER_SITES=	http://files.randombit.net/botan/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://botan.randombit.net/
COMMENT=	Portable, easy to use, and efficient C++ crypto library
LICENSE=	botan-license
LICENSE_FILE=	${FILESDIR}/botan-license

#BROKEN_IN=	pkgsrc-2006Q4

USE_TOOLS+=	perl

USE_LANGUAGES=	c++
REPLACE_PERL+=	./configure.pl
#HAS_CONFIGURE=	yes
CONFIG_SHELL=		perl
#CONFIGURE_SCRIPT=	./configure.pl
#CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

MAKE_FLAGS+=	LIB_OPT=${CXXFLAGS:Q}

CXXFLAGS.DragonFly+=	-D_DRAGONFLY_SOURCE
#CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE
BUILDLINK_TRANSFORM+=	rm:-mcpu=i686

pre-build:
	cd ${WRKSRC} && \
	${CONFIG_SHELL} ./configure.pl --prefix=${PREFIX:Q}

.include "../../mk/bsd.pkg.mk"
