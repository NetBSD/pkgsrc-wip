# $NetBSD: Makefile,v 1.4 2004/09/23 05:59:42 jlamwww Exp $
#

DISTNAME=		guile-gtk-0.40.90
CATEGORIES=		devel x11
MASTER_SITES=		http://www.ir.bbn.com/~gdt/pkgsrc-wip/

MAINTAINER=		gdt@ir.bbn.com
HOMEPAGE=		http://www.gnu.org/software/guile-gtk/
COMMENT=		Library to make GTK 1.2 accessible from guile

USE_BUILDLINK3=		# defined
USE_X11=		# defined
USE_LIBTOOL=		# defined

GNU_CONFIGURE=		# defined
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

.include "../../lang/guile/buildlink3.mk"
# Skip glade, because it pulls in gnome-libs.
# Later, make a new package for just the glade parts,
# or a BUILD_DEF.
# .include "../../devel/libglade/buildlink3.mk"
# glade-config may be in ${LOCALBASE}/bin, so force not using it.
CONFIGURE_ARGS+=	--without-glade
.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
