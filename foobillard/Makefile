# $NetBSD: Makefile,v 1.1.1.1 2003/08/18 13:38:09 xtraeme Exp $
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

.include "../../graphics/glut/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
