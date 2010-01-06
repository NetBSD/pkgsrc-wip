# $NetBSD: Makefile,v 1.2 2010/01/06 04:50:41 christtrekker Exp $
#

DISTNAME=	etoile-0.4.1
PKGNAME=	${DISTNAME:S/-/-services-/}
CATEGORIES=	gnustep 
MASTER_SITES=	http://download.gna.org/etoile/

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://etoileos.com/
COMMENT=	Desktop environment built on GNUstep - services
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/Etoile-0.4.1
USE_LANGUAGES=	objc
USE_TOOLS+=	gmake

MAKE_FILE=	GNUmakefile
#MAKE_ENV=	GNUSTEP_MAKEFILES=${LOCALBASE}/share/GNUstep/Makefiles

.include "../../devel/gnustep-make/gnustep.mk"

DEPENDS+=	etoile-core>=2.0.0:../../wip/etoile-core

.include "../../x11/xscreensaver/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
