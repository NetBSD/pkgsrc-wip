# $NetBSD: Makefile,v 1.1.1.1 2004/04/06 19:54:42 mpasternak Exp $
# $Id: Makefile,v 1.1.1.1 2004/04/06 19:54:42 mpasternak Exp $
#

DISTNAME=		glade-2.0.1
PKGNAME=		${DISTNAME:S/-/2-nognome-/}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/glade/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://glade.gnome.org/
COMMENT=		User interface builder for the GTK2+ toolkit and GNOME2

BUILD_USES_MSGFMT=	YES
DEPENDS+=		xdg-dirs>=1.1:../../misc/xdg-dirs

CONFLICTS+=		glade-*

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_X11=		YES
USE_LIBTOOL=		YES

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
