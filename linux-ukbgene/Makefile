# $NetBSD$

DISTNAME=	ukbgene_linkset
PKGNAME=	linux-ukbgene
CATEGORIES=	biology
MASTER_SITES=	http://biobank.ndph.ox.ac.uk/showcase/util/
EXTRACT_SUFX=	.tar

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://biobank.ndph.ox.ac.uk/showcase/util/
COMMENT=	Tool for accessing UK Biobank data
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR} # More than one possibility -- please check manually.
USE_LANGUAGES=	c++

ONLY_FOR_PLATFORM+=	Linux-*-*

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
