# $NetBSD: Makefile,v 1.3 2010/06/13 22:46:55 thomasklausner Exp $
#

DISTNAME=	MoleInvasion-0.4
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://download.tuxfamily.org/minvasion/packages/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://moleinvasion.tuxfamily.org/dokuwiki/doku.php?id=wiki:minv_en
COMMENT=	Platform game with moles
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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
.include "../../mk/bsd.pkg.mk"
