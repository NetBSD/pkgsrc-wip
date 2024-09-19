# $NetBSD: Makefile,v 1.5 2012/09/24 16:56:29 asau Exp $

DISTNAME=	terminal.app_0.9.4+cvs20051125.orig
PKGNAME=	Terminal-0.9.4
PKGREVISION=	2
CATEGORIES=	x11 gnustep
MASTER_SITES=	http://deb.debian.org/debian/pool/main/t/terminal.app/

MAINTAINER=	metaridley@mchsi.com
HOMEPAGE=	https://www.nongnu.org/backbone/apps.html
COMMENT=	GNUstep terminal emulator
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/terminal-0.9.4+cvs20051125
USE_LANGUAGES=	objc
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile
NO_CONFIGURE=	yes


.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
