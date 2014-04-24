# $NetBSD: Makefile,v 1.2 2014/04/24 21:32:53 christtrekker Exp $

DISTNAME=	${VERS}
PKGNAME=	megaglest-${VERS}
VERS=		3.9.1
CATEGORIES=	games
MASTER_SITES=	https://github.com/MegaGlest/megaglest-source/archive/
FETCH_USING=	wget

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://megaglest.org/
COMMENT=	Cross-platform 3D real-time-strategy game with seven factions
LICENSE=	gnu-gpl-v3
WRKSRC=		${WRKDIR}/megaglest-source-${VERS}
USE_TOOLS+=	cmake bash autoconf automake jam
REPLACE_BASH=	build-mg.sh

#Does not extract clean by itself. Upon fail, extract manually, uncomment
#this, and make again.
#do-extract:

do-build:
	cd ${WRKSRC} && ./build-mg.sh

.include "../../graphics/aalib/buildlink3.mk"
.include "../../x11/damageproto/buildlink3.mk"
.include "../../x11/dri2proto/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../audio/freealut/buildlink3.mk"
.include "../../x11/kbproto/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xf86vidmodeproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
