# $NetBSD: Makefile,v 1.4 2004/11/16 19:35:58 lexort Exp $

DISTNAME=	guile-gnome-platform-2.7.96
CATEGORIES=	devel
MASTER_SITES=	http://download.gna.org/guile-gnome/releases/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://home.gna.org/guile-gnome/
COMMENT=	Library to access gobject/glib/gtk and gnome from guile

DEPENDS+=	guile-slib>=2.4.2:../../wip/guile16-slib

USE_BUILDLINK3=		YES

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

USE_MAKEINFO=		YES
INFO_FILES=		guile-gnome-tutorial.info

.include "../../wip/g-wrap2/buildlink3.mk"
# XXX split into separate packages
.include "../../devel/libgnomeui/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
