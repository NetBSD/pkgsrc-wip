# $NetBSD: Makefile,v 1.1.1.1 2003/09/21 07:56:00 marmfield Exp $
#

DISTNAME=		kmplayer-0.8b
CATEGORIES=		wip
MASTER_SITES=		http://www.xs4all.nl/~jjvrieze/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		murray@river-styx.org
HOMEPAGE=		http://www.xs4all.nl/~jjvrieze/
COMMENT=		KDE frontend to mplayer

WRKSRC=		${WRKDIR}/kmplayer

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		yes

DEPENDS+=               kdemultimedia>=3.1.4:../../audio/kdemultimedia
DEPENDS+=               mplayer>=0:../../graphics/mplayer

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
