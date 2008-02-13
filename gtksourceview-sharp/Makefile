# $NetBSD: Makefile,v 1.2 2008/02/13 13:10:50 koifren Exp $

DISTNAME=	gtksourceview-sharp-2.0-0.10
CATEGORIES=	devel
MASTER_SITES=	http://go-mono.com/sources/gtksourceview-sharp-2.0/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/Gtk
COMMENT=	Bindings to the GtkSourceView widge

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../wip/mono/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../x11/gtk2-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
