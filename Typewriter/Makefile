# $NetBSD: Makefile,v 1.3 2012/11/17 10:39:33 kristerw Exp $

DISTNAME=	Typewriter-0.0.1
CATEGORIES=	editors gnustep

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://etoileos.com/
COMMENT=	General text editor for plain and rich format text
LICENSE=	modified-bsd

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile

# Following line sets up the GNUstep build environment.
.include "../../devel/gnustep-make/gnustep.mk"

SVN_REPOSITORIES=	etoile
SVN_ROOT.etoile=	http://svn.gna.org/svn/etoile/trunk/Etoile/Services/User/Typewriter
SVN_MODULE.etoile=	Typewriter

WRKSRC=			${WRKDIR}/$(SVN_MODULE.etoile)

.include "../../wip/mk/svn-package.mk"

DEPENDS+=	etoile-core-[0-9]*:../../wip/etoile-core
.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
