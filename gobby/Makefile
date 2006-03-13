# $NetBSD: Makefile,v 1.3 2006/03/13 15:34:27 absd Exp $
#

DISTNAME=		gobby-0.3.0
CATEGORIES=		editors net
MASTER_SITES=		http://releases.0x539.de/gobby/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://gobby.0x539.de/
COMMENT=		Collaborative text editor

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "options.mk"

PLIST_SRC+=		${PKGDIR}/PLIST.common

.include "../../net/howl/buildlink3.mk"
.include "../../wip/libobby/buildlink3.mk"
.include "../../wip/net6/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../textproc/libxml++2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
