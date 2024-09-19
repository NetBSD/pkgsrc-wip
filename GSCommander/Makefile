# $NetBSD: Makefile,v 1.3 2012/09/24 16:56:26 asau Exp $
#

DISTNAME=	GSCommander-0.1
PKGREVISION=	1
CATEGORIES=	x11 gnustep
MASTER_SITES=	http://www.nice.ch/~phip/

MAINTAINER=	metaridley@mchsi.com
HOMEPAGE=	http://www.nice.ch/~phip/softcorner.html
COMMENT=	Simple Unix command monitor for GNUstep

WRKSRC=		${WRKDIR}/GSCommander
USE_LANGUAGES=	objc
NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile
USE_TOOLS+=	gmake

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
