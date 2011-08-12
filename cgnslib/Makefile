# $NetBSD: Makefile,v 1.1.1.1 2011/08/12 23:35:17 jihbed Exp $
#

DISTNAME=	cgnslib_3.1.3-2
PKGNAME=	cgnslib-3.1.3-2
CATEGORIES=	science
MASTER_SITES=	http://garr.dl.sourceforge.net/project/cgns/cgnslib_3.1/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.cgns.org/
COMMENT=	CFD General Notation System library code
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/cgnslib_3.1.3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++ fortran

.include "../../devel/hdf5/buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
