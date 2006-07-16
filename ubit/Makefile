# $gd

#will became 5.0.0 when ready
DISTNAME=	ubit-5.0.0
PKGREVISION=	1
CATEGORIES=	x11

#MASTER_SITES will became ftp.enst.fr when ready.
#MASTER_SITES=	ftp://ftp.enst.fr/ubit/
MASTER_SITES=	http://perso.enst.fr/~dauphin/
DISTFILES=	${DISTNAME}.5.tar.gz
#EXTRACT_SUFX=	.tar.gz

MAINTAINER=	dauphin@enst.fr
HOMEPAGE=	http://perso.enst.fr/~elc/ubit/
COMMENT=	Ubiquitous Brick Interactive Toolkit

#PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

#CONFIGURE_ENV+=
CONFIGURE_ARGS+=	--with-gl-prefix=${LOCALBASE}

.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
