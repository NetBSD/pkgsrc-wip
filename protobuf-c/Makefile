# $NetBSD: Makefile,v 1.1 2013/01/13 00:42:39 wongk Exp $
#

DISTNAME=	protobuf-c-0.15
CATEGORIES=	devel
MASTER_SITES=	http://protobuf-c.googlecode.com/files/

MAINTAINER=	wongk@apt.homeunix.net
HOMEPAGE=	http://code.google.com/p/protobuf-c/
COMMENT=	Protocol Buffers for pure C
LICENSE=	modified-bsd

GNU_CONFIGURE=  yes
USE_LANGUAGES=  c++ c
USE_LIBTOOL=	yes

LIBS.SunOS= -lresolv -lsocket -lnsl

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	configure

CONFIGURE_ENV=	LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS=-L${LOCALBASE}/include

# url2pkg-marker (please do not remove this line.)
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
