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

# This neeeds to be set as environment variable, not sure how
#USE_CUDA=0

DEPENDS+=	${PYPKGPREFIX}-yaml>=5.4.1:../../textproc/py-yaml

WRKSRC=	${WRKDIR}/pytorch

post-extract:
	cd ${WRKDIR}; \
	git clone --recursive https://github.com/pytorch/pytorch; \
	cd pytorch; \
	git submodule sync; \
	git submodule update --init --recursive --jobs 0

# url2pkg-marker (please do not remove this line.)
.include "../../lang/python/egg.mk"
.include "../../devel/google-glog/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
