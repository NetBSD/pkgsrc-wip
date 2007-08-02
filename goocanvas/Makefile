# $NetBSD: Makefile,v 1.2 2007/08/02 15:13:19 makoto Exp $

DISTNAME=	goocanvas-0.4
CATEGORIES=	devel
MASTER_SITES=	http://www.dachaplin.dsl.pipex.com/goocanvas/

MAINTAINER=	makoto@ki.nu
HOMEPAGE=	http://www.dachaplin.dsl.pipex.com/goocanvas/
COMMENT=	"A Cairo Canvas Widget for GTK+"

GNU_CONFIGURE=	yes

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
