# $NetBSD: Makefile,v 1.3 2003/06/25 07:26:09 xtraeme Exp $
#

DISTNAME=	gmencoder-0.0.7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gmencoder/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://gmencoder.sourceforge.net/
COMMENT=	GTK2 Frontend to mencoder

DEPENDS+=       gnome2-dirs>=1.0:../../misc/gnome2-dirs
DEPENDS+=       mencoder-[0-9]*:../../graphics/mencoder
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

.include "../../mk/pthread.buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
