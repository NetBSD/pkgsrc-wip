# $NetBSD: Makefile,v 1.4 2003/12/14 02:23:50 marmfield Exp $
#

DISTNAME=		kmplayer-0.8.1a
WRKSRC=			${WRKDIR}/kmplayer
CATEGORIES=		wip graphics
MASTER_SITES=		http://www.xs4all.nl/~jjvrieze/

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		for_mplayer-1.0pre3.diff

MAINTAINER=		murray@river-styx.org
HOMEPAGE=		http://www.xs4all.nl/~jjvrieze/
COMMENT=		KDE frontend to mplayer

.include "../../meta-pkgs/kde3/Makefile.kde3"

DEPENDS+=               kdemultimedia>=3.1.4:../../audio/kdemultimedia3
DEPENDS+=               mplayer>=1.0rc3:../../graphics/mplayer
DEPENDS+=               mencoder>=1.0rc3:../../graphics/mencoder

USE_BUILDLINK2=		yes

do-patch:
	cd ${WRKSRC}/src && ${PATCH} -p0 < ${DISTDIR}/${PATCHFILES}

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
