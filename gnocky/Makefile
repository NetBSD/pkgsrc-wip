# $NetBSD: Makefile,v 1.4 2008/03/06 14:54:08 thomasklausner Exp $
#

DISTNAME=		gnocky-0.0.3
PKGREVISION=		3
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
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../wip/gnokii/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
