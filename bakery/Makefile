# $NetBSD: Makefile,v 1.4 2008/03/06 14:54:07 thomasklausner Exp $

DISTNAME=	bakery-2.4.1
PKGREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/bakery/2.4/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://bakery.sourceforge.net/
COMMENT=	C++ Framework for creating GNOME applications using gtkmm

GNU_CONFIGURE=	yes

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gconfmm/buildlink3.mk"
.include "../../devel/libglademm/buildlink3.mk"
.include "../../sysutils/gnome-vfsmm/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
