# $NetBSD: Makefile,v 1.7 2010/06/13 22:47:10 thomasklausner Exp $

DISTNAME=	libgtksourceviewmm-0.3.1
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgtksourceviewmm/0.3/}

MAINTAINER=	makoto@ki.nu
HOMEPAGE=	http://home.gna.org/gtksourceviewmm/
COMMENT=	C++ API for gtksourceview

USE_LANGUAGES+=	c c++
GNU_CONFIGURE=	YES

USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes
USE_DESTDIR=	yes

.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
#include "../../devel/doxygen/buildlink3.mk"
DEPENDS+= doxygen>=1.4:../../devel/doxygen

.include "../../mk/bsd.pkg.mk"
