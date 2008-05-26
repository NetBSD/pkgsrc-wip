# $NetBSD: Makefile,v 1.8 2008/05/26 13:59:47 tnn2 Exp $
#

DISTNAME=		scourge-0.4
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scourge/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://scourge.sourceforge.net/
COMMENT=		Graphical 3D roguelike, vermin extermination

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_FILE=		Makefile.Fedora

USE_LANGUAGES=		c c++
USE_TOOLS+=		pax

post-extract:
	${CP} ${FILESDIR}/scourge.sh ${WRKSRC}

SUBST_CLASSES+=	scourge
SUBST_MESSAGE.scourge=	Replacing prefix.
SUBST_STAGE.scourge=	post-patch
SUBST_FILES.scourge=	scourge.sh
SUBST_SED.scourge=	-e "s,XXXPREFIXXXX,${PREFIX},g"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/scourgedir
	${INSTALL_DATA_DIR} ${PREFIX}/share/scourgedir/data
	${INSTALL_DATA_DIR} ${PREFIX}/share/scourgedir/saved
	${INSTALL_PROGRAM} ${WRKSRC}/scourge ${PREFIX}/share/scourgedir
	${INSTALL_SCRIPT} ${WRKSRC}/scourge.sh ${PREFIX}/bin/scourge
	cd ${WRKSRC}/data && pax -rw . ${PREFIX}/share/scourgedir/data
	${INSTALL_DATA} ${WRKSRC}/saved/scourge.cfg \
		${PREFIX}/share/scourgedir/saved

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
