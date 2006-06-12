# $gd

#will became 5.0.0 when ready
DISTNAME=	vreng-6.6.2
PKGREVISION=	1
CATEGORIES=	x11

MASTER_SITES=	ftp://ftp.enst.fr/vreng/
DISTFILES=	${DISTNAME}.tar.gz
#EXTRACT_SUFX=	.tar.gz

MAINTAINER=	dauphin@enst.fr
HOMEPAGE=	http://vreng.enst.fr/
COMMENT=	Virtual Reality Engine interactive distributed 3D application

#PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_LANGUAGES+=	c c++
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

#CONFIGURE_ENV+=
#CONFIGURE_ARGS+= --enable-ocaml
CONFIGURE_ARGS+=	--with-GL-prefix=${LOCALBASE}

#mpeg
#java
.include "../../databases/mysql5-client/buildlink3.mk"
.include "../../wip/ubit/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../multimedia/mpeg-lib/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
