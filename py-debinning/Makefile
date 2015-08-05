# $NetBSD: Makefile,v 1.1 2015/08/05 21:34:31 jihbed Exp $

DISTNAME=	debinning-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://www.hepforge.org/archive/debinning/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://debinning.hepforge.org/
COMMENT=	The bias inherent when binning data  into histograms
#LICENSE=	# TODO: (see mk/license.mk)

#DEPENDS+=	root>=:../../misc/root

WRKSRC=		${WRKDIR}/debinning

USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
