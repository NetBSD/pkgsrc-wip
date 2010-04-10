# $NetBSD: Makefile,v 1.2 2010/04/10 20:18:25 jihbed Exp $
#

DISTNAME=	gvariant-0
CATEGORIES=	devel
MASTER_SITES=	http://people.gnome.org/~ryanl/src/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://people.gnome.org/~ryanl/src/
COMMENT=	GVariant is a new datatype in glib that stores complex values
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES= c c++

PKGCONFIG_OVERRIDE+=	glib/gvariant.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
