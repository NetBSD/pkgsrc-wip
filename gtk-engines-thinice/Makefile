# $NetBSD: Makefile,v 1.1.1.1 2003/08/30 17:40:22 blef Exp $

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
USE_GMAKE=		YES
USE_X11BASE=		YES

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
