# $NetBSD: Makefile,v 1.7 2005/04/11 21:12:57 tvierling Exp $

DISTNAME=	guile-gnome-platform-2.7.96
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.gna.org/guile-gnome/releases/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://home.gna.org/guile-gnome/
COMMENT=	Library to access gobject/glib/gtk and gnome from guile

DEPENDS+=	guile-slib>=2.4.2:../../devel/guile-slib


GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

USE_MAKEINFO=		YES
INFO_FILES=		guile-gnome-tutorial.info

.include "../../devel/g-wrap/buildlink3.mk"
# XXX split into separate packages
.include "../../devel/libgnomeui/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
