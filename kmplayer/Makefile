# $NetBSD: Makefile,v 1.3 2003/11/01 02:46:56 marmfield Exp $
#

DISTNAME=		kmplayer-0.8.1
WRKSRC=			${WRKDIR}/kmplayer
CATEGORIES=		wip graphics
MASTER_SITES=		http://www.xs4all.nl/~jjvrieze/

MAINTAINER=		murray@river-styx.org
HOMEPAGE=		http://www.xs4all.nl/~jjvrieze/
COMMENT=		KDE frontend to mplayer

.include "../../meta-pkgs/kde3/Makefile.kde3"

DEPENDS+=               kdemultimedia>=3.1.4:../../audio/kdemultimedia3
DEPENDS+=               mplayer>=1.0rc1:../../graphics/mplayer
DEPENDS+=               mencoder>=1.0rc1:../../graphics/mencoder

USE_BUILDLINK2=		yes

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
