# $NetBSD: Makefile,v 1.6 2004/01/25 02:11:31 grantbeattie Exp $
#

DISTNAME=	armagetron-0.2.5.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=armagetron/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	snj@pobox.com
HOMEPAGE=	http://armagetron.sourceforge.net/
COMMENT=	3D Tron lightcycle clone with network support

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES

CONFIGURE_ARGS+=	--disable-etc

REPLACE_INTERPRETER+=	bash
_REPLACE.bash.old=	.*/bin/bash
_REPLACE.bash.new=	${SH}
_REPLACE_FILES.bash=	batch/starter.in

post-build:
		cd ${WRKSRC} && ${MAKE_PROGRAM} bindist

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/games/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/${PKGBASE}/net
	${CP} -R ${WRKSRC}/bindist/* ${PREFIX}/games/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/html/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/net/*.html \
		${PREFIX}/share/doc/html/${PKGBASE}/net/
	${MV} ${PREFIX}/games/${PKGBASE}/bin/starter ${PREFIX}/bin/${PKGBASE}

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
