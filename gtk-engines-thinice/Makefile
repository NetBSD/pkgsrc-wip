# $NetBSD: Makefile,v 1.9 2007/02/03 09:20:27 thomasklausner Exp $

DISTNAME=	gtk-thinice-theme-1.0.4
PKGNAME=	gtk-engines-thinice-1.0.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=thinice/}

MAINTAINER=	snj@pobox.com
HOMEPAGE=	http://thinice.sourceforge.net/
COMMENT=	Simple, clean theme engine for gtk+ 1.2.x

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.4
USE_TOOLS+=		gmake
USE_X11BASE=		YES

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
