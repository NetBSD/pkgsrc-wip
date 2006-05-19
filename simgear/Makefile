# $NetBSD: Makefile,v 1.6 2006/05/19 16:51:36 ykomatsu Exp $
#

DISTNAME=		SimGear-0.3.4
PKGNAME=		${DISTNAME:S/SimGear/simgear/}
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.simgear.org/pub/simgear/Source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		ftp://ftp.simgear.org/pub/simgear/Source/
COMMENT=		Simulator Construction Tools

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
