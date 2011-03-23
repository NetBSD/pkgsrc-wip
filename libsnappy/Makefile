# $NetBSD: Makefile,v 1.2 2011/03/23 21:10:43 bharder Exp $
#
http://snappy.googlecode.com/files/snappy-1.0.0.tar.gz

DISTNAME=	snappy-1.0.0
CATEGORIES=	devel
# MASTER_SITES=	http://code.google.com/p/snappy/downloads/detail?name=
MASTER_SITES=	http://snappy.googlecode.com/files/
PKGREVISION=    1

MAINTAINER=	bch@methodlogic.net
HOMEPAGE=	http://code.google.com/p/snappy/downloads/
COMMENT=	A compression/decompression library.
LICENSE=	apache-2.0
GNU_CONFIGURE=	yes
CPPFLAGS+=	-DLZF_STATE_ARG="0"
USE_LANGUAGES+=	c++ c

PKG_DESTDIR_SUPPORT=	user-destdir

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
