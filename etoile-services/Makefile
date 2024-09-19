# $NetBSD: Makefile,v 1.3 2012/11/19 15:09:23 christtrekker Exp $
#

DISTNAME=	etoile-${VERSN}
PKGNAME=	${DISTNAME:S/-/-services-/}
PKGREVISION=	1
CATEGORIES=	gnustep
MASTER_SITES=	http://download.gna.org/etoile/
VERSN=		0.4.1

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://etoileos.com/
COMMENT=	Desktop environment built on GNUstep - services
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/Etoile-${VERSN}
USE_LANGUAGES=	objc
USE_TOOLS+=	gmake

MAKE_FILE=	GNUmakefile
#MAKE_ENV=	GNUSTEP_MAKEFILES=${LOCALBASE}/share/GNUstep/Makefiles

.include "../../devel/gnustep-make/gnustep.mk"

DEPENDS+=	etoile-core>=${VERSN}:../../wip/etoile-core

.include "../../x11/xscreensaver/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
