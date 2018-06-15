# $NetBSD$

DISTNAME=	din-35
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://archive.org/download/dinisnoise_source_code/

MAINTAINER=	santhosh.raju@gmail.com
HOMEPAGE=	https://dinisnoise.org/
COMMENT=	Open source cross-platform sound synthesizer
LICENSE=	gnu-gpl-v2

DEPENDS+=	boost-libs>=1.66:../../devel/boost-libs \
		SDL>=1.2.15:../../devel/SDL \
		Mesa>=7.11.2:../../graphics/MesaLib \
		alsa-lib>=1.1.4.1:../../audio/alsa-lib \
		jack>=0.124.1:../../audio/jack \
		tcl>=8.6.8:../../lang/tcl

USE_LANGUAGES=	c c++
USE_TOOLS+=	autoreconf pkg-config gmake
GNU_CONFIGURE=	yes

.include "options.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
