# $NetBSD: Makefile,v 1.4 2004/04/15 11:03:05 jmmv Exp $
#

DISTNAME=	gurlchecker-0.4.1
CATEGORIES=	www gnome2
MASTER_SITES=	http://savannah.nongnu.org/download/gurlchecker/stable/0.4/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/gurlchecker/
COMMENT=	Gnome2 program to check a page/website for broken links

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
