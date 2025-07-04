#	$NetBSD$

DISTNAME=	tnfrepo-0.0a20250704.dev6
PKGNAME=	${DISTNAME}
CATEGORIES=	sysutils
HG_REPO=	https://hg.mumble.net/campbell/tnfrepo
HG_TAG=		ede88ba6608480522bf7ffcf78abc3b3fac69197

MAINTAINER=	riastradh@NetBSD.org
HOMEPAGE=	https://hg.mumble.net/campbell/tnfrepo
COMMENT=	TNF source repository configuration
LICENSE=	2-clause-bsd AND gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.12.0:../../devel/py-flit_core

DEPENDS+=	${PYPKGPREFIX}-hg-evolve>=11.1.4:../../devel/py-hg-evolve
DEPENDS+=	${PYPKGPREFIX}-mercurial>=6.8.1:../../devel/py-mercurial
DEPENDS+=	git-base>=2.47.1:../../devel/git-base
DEPENDS+=	git-cinnabar>=0.7.0beta1:../../devel/git-cinnabar

TOOL_DEPENDS+=	${PYPKGPREFIX}-cram>=0.7:../../devel/py-cram

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	27

PYSETUPSUBDIR=	hghooks
USE_PYTEST=	no

INSTALL_MAKE_FLAGS+=	prefix=${PREFIX:Q}

pre-build:
	${RUN}cd ${WRKSRC} && ${BUILD_MAKE_CMD}

post-install:
	${RUN}cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS}	\
			-f ${MAKE_FILE} ${INSTALL_TARGET}

# Test requires install first.  This is intentional, so that it checks
# the Python modules were installed correctly and are functioning.
# (You can also do `bmake test-env' and then run `make check' in order
# to test without installing.)

do-test:
	${RUN}cd ${WRKSRC} && \
	cram-${PYVERSSUFFIX} --verbose tests/

.include "../../lang/python/wheel.mk"
.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
