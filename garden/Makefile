# $NetBSD$

DISTNAME=	garden-1.0.9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=garden/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://garden.sourceforge.net/drupal/
COMMENT=	Vertical shoot-em-up with nontraditional elements
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

#DEPENDS+=       doxygen>=1.8.2:../../devel/doxygen

# Patches can be omitted with
#CFLAGS += -fgnu89-inline

.include "../../devel/allegro/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
