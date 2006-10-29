# $NetBSD: Makefile,v 1.14 2006/10/29 08:32:41 shattered Exp $
#

DISTNAME=	DFBSee-0.7.4
PKGNAME=	${DISTNAME:S/DFBS/dfbs/}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.directfb.org/download/DFBSee/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.directfb.org/download/DFBSee/
COMMENT=	Image viewer for DirectFB

ONLY_FOR_PLATFORM=     Linux-*-* NetBSD-*-*

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

USE_LIBTOOL=		yes

.include "../../wip/directfb/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
