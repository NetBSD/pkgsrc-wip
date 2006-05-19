# $NetBSD: Makefile,v 1.10 2006/05/19 16:51:18 ykomatsu Exp $
#

DISTNAME=	gurlchecker-0.4.1
CATEGORIES=	www gnome2
MASTER_SITES=	http://savannah.nongnu.org/download/gurlchecker/stable/0.4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://labs.libre-entreprise.org/projects/gurlchecker/
COMMENT=	Gnome2 program to check a page/website for broken links

USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
