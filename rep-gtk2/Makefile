# $NetBSD: Makefile,v 1.1 2004/09/02 22:35:43 tnn2 Exp $

DISTNAME=		rep-gtk-0.18
PKGNAME=		rep-gtk2-0.18
CATEGORIES=		x11 lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rep-gtk/}

MAINTAINER=		tnn@netilium.org
HOMEPAGE=		http://rep-gtk.sourceforge.net/
COMMENT=		librep bindings for gtk2 (used by sawfish)

DEPENDS+=		librep>=0.17:../../lang/librep
DEPENDS+=               gtk2+>=2.4.0:../../x11/gtk2

CONFLICTS=		rep-gtk-*

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

REPEXECDIR=		libexec/rep/${MACHINE_GNU_PLATFORM}

.include "../../devel/libglade2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/librep/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
