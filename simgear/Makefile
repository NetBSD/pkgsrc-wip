# $NetBSD: Makefile,v 1.2 2004/03/19 05:22:37 xtraeme Exp $
#

DISTNAME=		SimGear-0.3.4
PKGNAME=		${DISTNAME:S/SimGear/simgear/}
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.simgear.org/pub/simgear/Source/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		ftp://ftp.simgear.org/pub/simgear/Source/
COMMENT=		Simulator Construction Tools

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
