# $NetBSD: Makefile,v 1.2 2004/02/17 02:55:46 blef Exp $
#

DISTNAME=		kyra_src_1_6_5
PKGNAME=		kyra-1.6.5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kyra/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://kyra.sourceforge.net/
COMMENT=		Sprite engine in C++ that uses SDL library

WRKSRC=		${WRKDIR}/kyra
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.if exists(../../mk/opengl.buildlink2.mk)
.include "../../mk/opengl.buildlink2.mk"
.else
.include "../../graphics/MesaLib/buildlink2.mk"
.endif
.include "../../mk/bsd.pkg.mk"
