# $NetBSD: Makefile,v 1.2 2010/12/14 16:59:56 noud4 Exp $
#

DISTNAME=	libopensync-plugin-gnokii-0.22
CATEGORIES=	comms
MASTER_SITES=	http://www.opensync.org/download/releases/0.22/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	noud4@home.nl
HOMEPAGE=	http://www.opensync.org/download/releases/0.22/
COMMENT=	Platform independent synchronization framework, gnokii plugin

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../wip/gnokii/buildlink3.mk"

.include "../../comms/libopensync/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
