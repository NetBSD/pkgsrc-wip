# $NetBSD: Makefile,v 1.3 2008/01/28 22:19:03 dvol Exp $
#

PKGNAME=	TextEdit-4.0
DISTNAME=	textedit.app_4.0.orig
PKGREVISION=	2
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
