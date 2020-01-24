# $NetBSD$

DISTNAME=	atanks-6.5
CATEGORIES=	wip
#Nope.txt
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=atanks}
MASTER_SITES=	https://sourceforge.net/projects/atanks/files/atanks/atanks-6.5/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://atanks.sourceforge.net/
COMMENT=	Multi-platform Scorched Earth clone
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++
#MAKE_ARGS+=	PREFIX=${PREFIX}/
#MAKE_ARGS+=	CC=${CC} CPP=${CXX} LD=${LD}

.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
