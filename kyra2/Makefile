# $NetBSD: Makefile,v 1.13 2013/01/04 18:10:07 kristerw Exp $
#

DISTNAME=	kyra_src_2_1_3
PKGNAME=	${DISTNAME:S/kyra_src_/kyra2-/1:S/_/./g}
WRKSRC=		${WRKDIR}/kyra
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kyra/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.grinninglizard.com/kyra/index.html
COMMENT=	Sprite engine
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf automake gmake perl

pre-configure:
	cd ${WRKSRC} && ${SH} autogen

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
