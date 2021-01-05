# $NetBSD: Makefile,v 1.2 2015/06/30 02:32:02 cfkoch Exp $

VERSION=	0.8.1
DISTNAME=	libucl-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=vstakhov/}

MAINTAINER=	cfkoch@edgebsd.org
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
