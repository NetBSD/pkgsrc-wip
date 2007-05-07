# $NetBSD: Makefile,v 1.7 2007/05/07 19:13:37 tnn2 Exp $

DISTNAME=		rep-gtk-0.18
PKGNAME=		rep-gtk2-0.18
CATEGORIES=		x11 lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rep-gtk/}

MAINTAINER=		tnn+nbsd@nygren.pp.se
HOMEPAGE=		http://rep-gtk.sourceforge.net/
COMMENT=		librep bindings for gtk2 (used by sawfish)

DEPENDS+=		librep>=0.17nb3:../../lang/librep
DEPENDS+=		gtk2+>=2.4.0:../../x11/gtk2

CONFLICTS=		rep-gtk-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../devel/libglade2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/librep/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
