# $NetBSD: Makefile,v 1.1 2015/06/22 00:34:20 cfkoch Exp $

VERSION=	0.7.3
DISTNAME=	libucl-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	-https://codeload.github.com/vstakhov/libucl/tar.gz/${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vstakhov/libucl
COMMENT=	Universal configuration library parser
LICENSE=	2-clause-bsd

USE_LANGUAGES+=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf gmake
HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && sh ./autogen.sh

.include "../../mk/bsd.pkg.mk"
