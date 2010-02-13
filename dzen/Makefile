# $NetBSD: Makefile,v 1.5 2010/02/13 12:33:27 jtonio Exp $
#

DISTNAME=	dzen2-0.8.5
PKGREVISION=	1
CATEGORIES=	x11 misc
MASTER_SITES=	http://gotmor.googlepages.com/

MAINTAINER=	pikapika@8-0.net
HOMEPAGE=	http://gotmor.googlepages.com/
COMMENT=	General purpose messaging and notification program

LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
BUILD_DIRS=		. gadgets

INSTALLATION_DIRS=	bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
