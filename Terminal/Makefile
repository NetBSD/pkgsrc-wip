# $NetBSD: Makefile,v 1.1.1.1 2007/08/12 01:54:42 dvol Exp $
#

PKGNAME=	Terminal-0.9.4
DISTNAME=	terminal.app_0.9.4+cvs20051125.orig
CATEGORIES=	x11 gnustep
MASTER_SITES=	ftp://ftp.it.debian.org/debian/pool/main/t/terminal.app/

MAINTAINER=	metaridley@mchsi.com
HOMEPAGE=	http://www.nongnu.org/backbone/apps.html
COMMENT=	GNUstep terminal emulator

WRKSRC=		${WRKDIR}/terminal-0.9.4+cvs20051125
USE_LANGUAGES=	objc
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile
NO_CONFIGURE=	yes


.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
