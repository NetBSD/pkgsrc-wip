# $NetBSD: Makefile,v 1.3 2012/09/29 00:50:42 asau Exp $
#

DISTNAME=	gvariant-0
CATEGORIES=	devel
MASTER_SITES=	http://people.gnome.org/~ryanl/src/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://people.gnome.org/~ryanl/src/
COMMENT=	GVariant is a new datatype in glib that stores complex values
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	glib/gvariant.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
