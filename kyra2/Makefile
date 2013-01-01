# $NetBSD: Makefile,v 1.12 2013/01/01 01:15:36 othyro Exp $
#

DISTNAME=	kyra_src_2_1_3
PKGNAME=	${DISTNAME:S/_src_/-/1:S/_/./g}
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
