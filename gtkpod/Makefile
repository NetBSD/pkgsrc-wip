# $NetBSD: Makefile,v 1.2 2004/04/25 00:13:28 thomasklausner Exp $
#

DISTNAME=	gtkpod-0.51-2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkpod/}

MAINTAINER=	david@dyn-ns.net
HOMEPAGE=	http://gtkpod.sourceforge.net
COMMENT=	GUI for iPod using GTK2

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_X11=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_GETTEXT=	yes

.include "../../audio/id3lib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
