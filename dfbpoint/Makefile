# $NetBSD: Makefile,v 1.15 2012/09/28 21:24:35 asau Exp $
#

DISTNAME=	DFBPoint-0.7.2
PKGNAME=	${DISTNAME:S/DFBP/dfbp/}
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.directfb.org/download/DFBPoint/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.directfb.org/
COMMENT=	Simple presentation viewer that uses the DirectFB
LICENSE=	gnu-lgpl-v2.1

ONLY_FOR_PLATFORM=	Linux-*-*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../wip/directfb/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
