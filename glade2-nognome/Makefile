# $NetBSD: Makefile,v 1.16 2013/01/10 15:16:43 othyro Exp $
# $Id: Makefile,v 1.16 2013/01/10 15:16:43 othyro Exp $
#

DISTNAME=	glade-2.0.1
PKGNAME=	${DISTNAME:S/-/2-nognome-/}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glade/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://glade.gnome.org/
COMMENT=	User interface builder for the GTK2+ toolkit and GNOME2

CONFLICTS+=	glade-*


GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake msgfmt perl pkg-config
USE_LIBTOOL=		YES


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
