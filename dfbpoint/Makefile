# $NetBSD: Makefile,v 1.2 2003/06/06 20:37:26 xtraeme Exp $
#

DISTNAME=	DFBPoint-0.7.2
PKGNAME=	${DISTNAME:S/DFBP/dfbp/}
CATEGORIES=	graphics
MASTER_SITES=	http://www.directfb.org/download/DFBPoint/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.directfb.org/
COMMENT=	Simple presentation viewer that uses the DirectFB

ONLY_FOR_PLATFORM=     Linux-*-*

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../wip/directfb/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
