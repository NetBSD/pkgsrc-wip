# $NetBSD: Makefile,v 1.3 2003/09/08 04:02:49 blef Exp $
#

DISTNAME=	armagetron-0.2.4
CATEGORIES=	games
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=armagetron/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	snj@pobox.com
HOMEPAGE=	http://armagetron.sourceforge.net/
COMMENT=	3D Tron lightcycle clone with network support

GNU_CONFIGURE=	YES
USE_BUILDLINK2= YES
USE_GMAKE=	YES

REPLACE_INTERPRETER+=  bash
_REPLACE.bash.old=     .*/bin/bash
_REPLACE.bash.new=     ${SH}
_REPLACE_FILES.bash=   batch/starter.in

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
