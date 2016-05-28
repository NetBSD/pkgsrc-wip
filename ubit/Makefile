# $NetBSD: Makefile,v 1.13 2014/10/09 14:06:31 thomasklausner Exp $

#DISTNAME=	ubit-5.0.4
DISTNAME=	ubit-5.5.0
PKGREVISION=	2
CATEGORIES=	x11

MASTER_SITES=	ftp://ftp.enst.fr/pub/ubit/
DISTFILES=	${DISTNAME}.tar.gz
#EXTRACT_SUFX=	.tar.gz

MAINTAINER=	dauphin@enst.fr
HOMEPAGE=	http://perso.enst.fr/~elc/ubit/
COMMENT=	Ubiquitous Brick Interactive Toolkit


USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

#CONFIGURE_ENV+=
CONFIGURE_ARGS+=	--with-gl-prefix=${LOCALBASE}

.include "../../graphics/giflib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
