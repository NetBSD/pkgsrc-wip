# $NetBSD: Makefile,v 1.4 2014/02/11 21:04:07 noud4 Exp $
#

DISTNAME=	libopensync-plugin-palm-0.22
CATEGORIES=	comms
##MASTER_SITES=	http://www.opensync.org/download/releases/0.22/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	noud4@users.sourceforge.net
##HOMEPAGE=	http://www.opensync.org/download/releases/0.22/
COMMENT=	Platform independent synchronization framework, palm plugin

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../comms/pilot-link-libs/buildlink3.mk"

.include "../../comms/libopensync/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
