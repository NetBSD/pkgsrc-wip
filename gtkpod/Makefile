# $NetBSD: Makefile,v 1.1.1.1 2003/09/17 15:40:12 xtraeme Exp $
#

DISTNAME=	gtkpod-0.51-2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkpod/}

MAINTAINER=	david@dyn-ns.net
HOMEPAGE=	http://gtkpod.sourceforge.net
COMMENT=	GUI for iPod using GTK2

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_X11=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_GETTEXT=	yes

.include "../../audio/id3lib/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
