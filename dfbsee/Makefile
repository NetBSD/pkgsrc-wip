# $NetBSD: Makefile,v 1.2 2003/06/06 20:29:39 xtraeme Exp $
#

DISTNAME=	DFBSee-0.7.4
PKGNAME=	${DISTNAME:S/DFBS/dfbs/}
CATEGORIES=	graphics
MASTER_SITES=	http://www.directfb.org/download/DFBSee/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.directfb.org/download/DFBSee/
COMMENT=	Image viewer for DirectFB

ONLY_FOR_PLATFORM=     Linux-*-*

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

USE_LIBTOOL=            yes
LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../wip/directfb/buildlink2.mk"

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
