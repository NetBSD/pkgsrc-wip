# $NetBSD: Makefile,v 1.4 2012/06/13 05:16:03 othyro Exp $
#

PKGNAME=	Terminal-0.9.4
DISTNAME=	terminal.app_0.9.4+cvs20051125.orig
PKGREVISION=	2
CATEGORIES=	x11 gnustep
MASTER_SITES=	ftp://ftp.it.debian.org/debian/pool/main/t/terminal.app/

MAINTAINER=	metaridley@mchsi.com
HOMEPAGE=	http://www.nongnu.org/backbone/apps.html
COMMENT=	GNUstep terminal emulator
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/terminal-0.9.4+cvs20051125
USE_LANGUAGES=	objc
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile
NO_CONFIGURE=	yes


.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
