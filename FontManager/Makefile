# $NetBSD: Makefile,v 1.2 2012/09/24 16:56:26 asau Exp $

DISTNAME=	FontManager-0.0.1
CATEGORIES=	fonts gnustep

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://etoileos.com/
COMMENT=	Font Manager is an app for the purpose of (guess what) managing fonts
LICENSE=	modified-bsd

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile

# Following line sets up the GNUstep build environment.
.include "../../devel/gnustep-make/gnustep.mk"

SVN_REPOSITORIES=	etoile
SVN_ROOT.etoile=	http://svn.gna.org/svn/etoile/trunk/Etoile/Services/User/FontManager
SVN_MODULE.etoile=	FontManager

WRKSRC=			${WRKDIR}/$(SVN_MODULE.etoile)

.include "../../wip/mk/svn-package.mk"

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
