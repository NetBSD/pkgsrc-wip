# $NetBSD: Makefile,v 1.1.1.1 2003/06/24 05:05:21 xtraeme Exp $
#

DISTNAME=	gurlchecker-0.4.1
CATEGORIES=	www gnome2
MASTER_SITES=	http://savannah.nongnu.org/download/gurlchecker/stable/0.4/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/gurlchecker/
COMMENT=	Gnome2 program to check a page/website for broken links

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
