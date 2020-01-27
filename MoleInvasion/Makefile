# $NetBSD: Makefile,v 1.5 2012/09/24 16:56:27 asau Exp $
#

DISTNAME=	MoleInvasion-0.4
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://download.tuxfamily.org/minvasion/packages/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://moleinvasion.tuxfamily.org/dokuwiki/doku.php?id=wiki:minv_en
COMMENT=	Platform game with moles
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/moleinvasion-0.4
BUILD_DIRS=		src
USE_TOOLS+=		gmake
INSTALL_TARGET=		install install-data
INSTALLATION_DIRS=	${PKGMANDIR}/man6

post-install:
	${INSTALL_MAN} ${WRKSRC}/debian/*.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
