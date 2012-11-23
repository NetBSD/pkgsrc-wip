# $NetBSD: Makefile,v 1.3 2012/11/23 22:33:39 othyro Exp $
#

DISTNAME=	libopensync-plugin-palm-0.22
CATEGORIES=	comms
MASTER_SITES=	http://www.opensync.org/download/releases/0.22/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	noud4@home.nl
HOMEPAGE=	http://www.opensync.org/download/releases/0.22/
COMMENT=	Platform independent synchronization framework, palm plugin

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../comms/pilot-link-libs/buildlink3.mk"

.include "../../comms/libopensync/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
