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

DEPENDS+=	${PYPKGPREFIX}-yaml>=5.4.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10.0.2:../../devel/py-typing-extensions
DEPENDS+=	git-base-[0-9]*:../../devel/git-base
DEPENDS+=	cmake>=3.17:../../devel/cmake
DEPENDS+=	protobuf>=3.20.1:../../devel/protobuf

USE_CMAKE=	yes
CMAKE_CONFIGURE_ARGS+=	-B build \
		-DBUILD_SHARED_LIBS:BOOL=ON \
		-DBUILD_BINARY:BOOL=ON \
		-DBUILD_CAFFE2=OFF \
		-DCMAKE_BUILD_TYPE:STRING=Release \
		-DBUILD_PYTHON=OFF \
		-DBUILD_TEST=OFF \
		-DONNX_ML=OFF \
		-DUSE_OPENCV=ON \
		-DUSE_CUDA=OFF \
		-DUSE_CUDNN=OFF \
		-DUSE_BREAKPAD=OFF \
		-DUSE_FBGEMM=OFF \
		-DUSE_KINETO=OFF \
		-DBUILD_CUSTOM_PROTOBUF=OFF \
		-DUSE_{Q/X}NNPACK=OFF

USE_LANGUAGES+=	c c++

CFLAGS+=	-fopenmp
CPPFLAGS+=	-fopenmp

WRKSRC=	${WRKDIR}/pytorch

BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl
BUILDLINK_TRANSFORM.NetBSD+=	l:libgomp:gomp # Otherwise it links -llibgomp
BUILDLINK_TRANSFORM.NetBSD+=	opt:-std=c++14:-std=gnu++14 # alloca
BUILDLINK_TRANSFORM.NetBSD+=	opt:-std=c99:-std=gnu99 # alloca

post-extract:
	rsync -a /tmp/pytorch ${WRKDIR}
	# This step takes long. During development use a local copy
	#cd ${WRKDIR}; \
	#git clone --recursive https://github.com/pytorch/pytorch; \
	#cd pytorch; \
	#git submodule sync; \
	#git submodule update --init --recursive --jobs 0

# url2pkg-marker (please do not remove this line.)
.include "../../devel/google-glog/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../parallel/openmp/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
