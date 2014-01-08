# $NetBSD: Makefile,v 1.2 2014/01/08 18:22:08 christtrekker Exp $

DISTNAME=	starplot-0.95.5
CATEGORIES=	misc x11
MASTER_SITES=	http://starplot.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://starplot.org/
COMMENT=	3-dimensional star chart viewer
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
