# $NetBSD: Makefile,v 1.3 2004/02/17 02:55:37 blef Exp $

DISTNAME=	gtk-thinice-theme-1.0.4
PKGNAME=	gtk-engines-thinice-1.0.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=thinice/}

MAINTAINER=	snj@pobox.com
HOMEPAGE=	http://thinice.sourceforge.net/
COMMENT=	Simple, clean theme engine for gtk+ 1.2.x

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_X11BASE=		YES

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
