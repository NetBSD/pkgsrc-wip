# $NetBSD: Makefile,v 1.18 2012/09/28 21:24:35 asau Exp $
#

DISTNAME=	DFBSee-0.7.4
PKGNAME=	${DISTNAME:S/DFBS/dfbs/}
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.directfb.org/download/DFBSee/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.directfb.org/download/DFBSee/
COMMENT=	Image viewer for DirectFB
LICENSE=	gnu-lgpl-v2.1

ONLY_FOR_PLATFORM=	Linux-*-* NetBSD-*-*

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

USE_LIBTOOL=		yes

.include "../../wip/directfb/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
