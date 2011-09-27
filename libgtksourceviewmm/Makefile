# $NetBSD: Makefile,v 1.8 2011/09/27 02:21:25 makoto Exp $

DISTNAME=	libgtksourceviewmm-0.3.1
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgtksourceviewmm/0.3/}

MAINTAINER=	makoto@ki.nu
HOMEPAGE=	http://projects.gnome.org/gtksourceviewmm/
COMMENT=	C++ API for gtksourceview
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c c++
GNU_CONFIGURE=	YES

USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
#include "../../devel/doxygen/buildlink3.mk"
DEPENDS+= doxygen>=1.4:../../devel/doxygen

.include "../../mk/bsd.pkg.mk"
