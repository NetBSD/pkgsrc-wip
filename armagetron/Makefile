# $NetBSD: Makefile,v 1.1.1.1 2003/08/07 07:55:13 amadeus_z Exp $
#

DISTNAME=	armagetron-0.2.4
CATEGORIES=	games
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=armagetron/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	poff@sixbit.org
HOMEPAGE=	http://armagetron.sourceforge.net/
COMMENT=	3D Tron lightcycle clone with network support

GNU_CONFIGURE=	YES
USE_BUILDLINK2= YES
USE_GMAKE=	YES

CONFIGURE_ARGS+=        --disable-etc

post-build:
		cd ${WRKSRC} && ${GMAKE} bindist

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/games/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/docs/html/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/docs/html/${PKGBASE}/net
	${CP} -R ${WRKSRC}/bindist/* ${PREFIX}/games/${PKGBASE}
	${CP} ${WRKSRC}/doc/*.html ${PREFIX}/share/docs/html/${PKGBASE}/
	${CP} ${WRKSRC}/doc/net/*.html ${PREFIX}/share/docs/html/${PKGBASE}/net/
	${MV} ${PREFIX}/games/${PKGBASE}/bin/starter ${PREFIX}/bin/${PKGBASE}

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
