# $NetBSD: Makefile,v 1.5 2004/02/17 02:55:17 blef Exp $
#

DISTNAME=	DFBPoint-0.7.2
PKGNAME=	${DISTNAME:S/DFBP/dfbp/}
CATEGORIES=	graphics
MASTER_SITES=	http://www.directfb.org/download/DFBPoint/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.directfb.org/
COMMENT=	Simple presentation viewer that uses the DirectFB

ONLY_FOR_PLATFORM=     Linux-*-*

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../wip/directfb/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
