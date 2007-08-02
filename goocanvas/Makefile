# $NetBSD: Makefile,v 1.3 2007/08/02 16:12:22 makoto Exp $

DISTNAME=	goocanvas-0.8
CATEGORIES=	devel
MASTER_SITES=	http://downloads.sourceforge.net/goocanvas/

MAINTAINER=	makoto@ki.nu
HOMEPAGE=	http://sourceforge.net/projects/goocanvas/
COMMENT=	A Cairo Canvas Widget for GTK+

GNU_CONFIGURE=	yes

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
USE_DESTDIR=	yes

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
