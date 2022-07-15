# $NetBSD$

DISTNAME=	pytorch-1.12.0
PKGNAME=	${PYPKGPREFIX}-torch-1.12.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=pytorch/}
GITHUB_PROJECT=	pytorch
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pytorch.org/
COMMENT=	Tensors and Dynamic neural networks in Python with GPU acceleration
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=	${WRKDIR}/pytorch-1.12.0

# url2pkg-marker (please do not remove this line.)
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
