# $NetBSD$

DISTNAME=	onnxruntime-1.25.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=microsoft/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/onnxruntime/
COMMENT=	Cross-platform, high performance ML inferencing and training accelerator
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

USE_TOOLS+=	git

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} ${WRKSRC}/tools/ci_build/build.py --build_dir ${WRKSRC}/build/Linux

.include "../../lang/python/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
