# $NetBSD: Makefile,v 1.1 2007/02/02 13:02:40 koifren Exp $
#

DISTNAME=		gnocky-0.0.3
CATEGORIES=		comms
MASTER_SITES=		http://www.gnokii.org/download/gnocky/

MAINTAINER=		kefren@netbsd.ro
HOMEPAGE=		http://www.gnokii.org/
COMMENT=		GTK-2 based frontend for gnokii

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_X11=		yes
USE_TOOLS+=		gmake

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../wip/gnokii/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
