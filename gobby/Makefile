# $NetBSD: Makefile,v 1.1.1.1 2005/09/11 06:32:14 udontknow Exp $
#

DISTNAME=		gobby-0.2.2
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
.include "../../wip/libxml++2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
