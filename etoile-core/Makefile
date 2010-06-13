# $NetBSD: Makefile,v 1.4 2010/06/13 22:47:03 thomasklausner Exp $
#

DISTNAME=	etoile-0.4.1
PKGNAME=	${DISTNAME:S/-/-core-/}
PKGREVISION=	1
CATEGORIES=	gnustep
MASTER_SITES=	http://download.gna.org/etoile/

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://etoileos.com/
COMMENT=	Desktop environment built on GNUstep - core
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/Etoile-0.4.1
USE_LANGUAGES=	objc c++
USE_TOOLS+=	gmake

NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile
#MAKE_ENV=	GNUSTEP_MAKEFILES=${LOCALBASE}/share/GNUstep/Makefiles

# Following line sets up the GNUstep build environment.
.include "../../devel/gnustep-make/gnustep.mk"

DEPENDS+=	gnustep-make>=2.0.8:../../devel/gnustep-make
#DEPENDS+=	gnustep-base>=1.18.0:../../devel/gnustep-base
#DEPENDS+=	gnustep-gui>=0.16.0:../../x11/gnustep-gui
DEPENDS+=	gnustep-back>=0.16.0:../../x11/gnustep-back
DEPENDS+=	lemon>=1.0.0:../../devel/lemon
#DEPENDS+=	postgresql83>=8.3.0:../../databases/postgresql83

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../wip/llvm/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"
# OSS   http://www.opensound.com/

.include "../../mk/bsd.pkg.mk"
