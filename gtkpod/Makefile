# $NetBSD: Makefile,v 1.4 2005/04/11 21:12:57 tvierling Exp $
#

DISTNAME=	gtkpod-0.51-2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkpod/}

MAINTAINER=	david@dyn-ns.net
HOMEPAGE=	http://gtkpod.sourceforge.net/
COMMENT=	GUI for iPod using GTK2

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_X11=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_GETTEXT=	yes

.include "../../audio/id3lib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
