# $NetBSD: Makefile,v 1.6 2004/09/23 05:59:39 jlamwww Exp $

DISTNAME=	gtk-thinice-theme-1.0.4
PKGNAME=	gtk-engines-thinice-1.0.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=thinice/}

MAINTAINER=	snj@pobox.com
HOMEPAGE=	http://thinice.sourceforge.net/
COMMENT=	Simple, clean theme engine for gtk+ 1.2.x

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_X11BASE=		YES

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
