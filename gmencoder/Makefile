# $NetBSD: Makefile,v 1.1.1.1 2003/04/23 18:08:35 xtraeme Exp $
#

DISTNAME=	gmencoder-0.0.7		
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gmencoder/}	
EXTRACT_SUFX=	.tgz	

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://gmencoder.sourceforge.net/
COMMENT=	GTK2 Frontend to mencoder

BUILD_USES_MSGFMT=	yes

DEPENDS+=	gnome2-dirs>=1.0:../../misc/gnome2-dirs
DEPENDS+=	mencoder-[0-9]*:../../graphics/mencoder

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

.include "../../mk/pthread.buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
