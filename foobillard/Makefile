# $NetBSD: Makefile,v 1.2 2003/08/19 04:14:23 xtraeme Exp $
#

DISTNAME=	foobillard-2.8
CATEGORIES=	games
MASTER_SITES=	http://foobillard.sunsite.dk/dnl/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://foobillard.sunsite.dk/
COMMENT=	Free OpenGL-billard game

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--enable-nvidia=no
.include "../../devel/SDL/buildlink2.mk"
.else
CONFIGURE_ARGS+=	--enable-glut
.endif

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
