# $NetBSD: Makefile,v 1.1.1.1 2007/08/15 08:26:18 dvol Exp $
#

PKGNAME=	TextEdit-4.0
DISTNAME=	textedit.app_4.0.orig
CATEGORIES=	editors gnustep
MASTER_SITES=	http://www.gtlib.cc.gatech.edu/pub/debian/pool/main/t/textedit.app/

MAINTAINER=	metaridley@mchsi.com
HOMEPAGE=	http://www.nongnu.org/backbone/apps.html
COMMENT=	GNUstep text editor

WRKSRC=		${WRKDIR}/textedit-4.0
NO_CONFIGURE=	yes
USE_LANGUAGES=	objc
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
