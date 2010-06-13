# $NetBSD: Makefile,v 1.6 2010/06/13 22:47:05 thomasklausner Exp $
#

DISTNAME=		gnocky-0.0.7
PKGREVISION=		1
CATEGORIES=		comms
MASTER_SITES=		http://www.gnokii.org/download/gnocky/

MAINTAINER=		kefren@netbsd.ro
HOMEPAGE=		http://www.gnokii.org/
COMMENT=		GTK-2 based frontend for gnokii

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_X11=		yes
USE_TOOLS+=		gmake

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../wip/gnokii/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
