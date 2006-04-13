# $NetBSD: Makefile,v 1.6 2006/04/13 18:18:14 jlamwww Exp $
#

DISTNAME=	gtkpod-0.51-2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkpod/}

MAINTAINER=	david@dyn-ns.net
HOMEPAGE=	http://gtkpod.sourceforge.net/
COMMENT=	GUI for iPod using GTK2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_GETTEXT=	yes
USE_TOOLS+=		msgfmt

.include "../../audio/id3lib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
