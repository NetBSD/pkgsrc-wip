# $NetBSD: Makefile,v 1.5 2012/11/13 19:33:45 othyro Exp $
#
http://snappy.googlecode.com/files/snappy-1.0.0.tar.gz

DISTNAME=	snappy-1.0.1
CATEGORIES=	devel
# MASTER_SITES=	http://code.google.com/p/snappy/downloads/detail?name=
MASTER_SITES=	http://snappy.googlecode.com/files/

MAINTAINER=	bch@methodlogic.net
HOMEPAGE=	http://code.google.com/p/snappy/downloads/
COMMENT=	A compression/decompression library.
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CPPFLAGS+=	-DLZF_STATE_ARG="0"
USE_LANGUAGES+=	c++ c

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
