# $NetBSD: Makefile,v 1.18 2014/10/09 14:06:32 thomasklausner Exp $

#DISTNAME=	vreng-6.8.3
DISTNAME=	vreng-6.8.12
PKGREVISION=	5
CATEGORIES=	x11

MASTER_SITES=	ftp://ftp.enst.fr/pub/vreng/
DISTFILES=	${DISTNAME}.tar.gz
#EXTRACT_SUFX=	.tar.gz

MAINTAINER=	dauphin@enst.fr
HOMEPAGE=	http://vreng.enst.fr/
COMMENT=	Virtual Reality Engine interactive distributed 3D application


USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
CXXFLAGS=	-g
CFLAGS=		-g
CXXFLAGS+=	-D_POSIX_PTHREAD_SEMANTICS
CFLAGS+=	-D_POSIX_PTHREAD_SEMANTICS

#CONFIGURE_ENV+=
#CONFIGURE_ARGS+=	--enable-ocaml
CONFIGURE_ARGS+=	--with-GL-prefix=${LOCALBASE}
CONFIGURE_ENV+=		PERLPATH=${LOCALBASE}/bin/perl

#mpeg
#java
.include "../../databases/mysql56-client/buildlink3.mk"
#BUILDLINK_LDFLAGS.mysql-client?=        -Wl,-R${LOCALBASE}/lib/mysql
LDFLAGS.SunOS+=		-R${LOCALBASE}/lib/mysql
LIBS.SunOS+=		-R${LOCALBASE}/lib/mysql
.include "../../lang/perl5/buildlink3.mk"
.include "../../wip/ubit/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../lang/ocaml/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../multimedia/mpeg-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
