# $NetBSD: Makefile,v 1.3 2012/09/24 18:26:52 asau Exp $
#

DISTNAME=	cgnslib_3.1.3-2
PKGNAME=	cgnslib-3.1.3-2
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/cgns/cgnslib_3.1/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.cgns.org/
COMMENT=	CFD General Notation System library code
LICENSE=	png-license

WRKSRC=		${WRKDIR}/cgnslib_3.1.3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++ fortran

.include "../../devel/hdf5/buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
