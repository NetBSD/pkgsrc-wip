#	$NetBSD$

DISTNAME=	tnfrepo-0.0a20250823.dev127
PKGREVISION=	1
PKGNAME=	${DISTNAME}
CATEGORIES=	sysutils
HG_REPO=	https://hg.mumble.net/campbell/tnfrepo
HG_TAG=		606fbb7a64fa46237f9da78edbc27e54022c622b

MAINTAINER=	riastradh@NetBSD.org
HOMEPAGE=	https://hg.mumble.net/campbell/tnfrepo
COMMENT=	TNF source repository configuration
LICENSE=	2-clause-bsd AND gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.12.0:../../devel/py-flit_core

DEPENDS+=	${PYPKGPREFIX}-hg-evolve>=11.1.4:../../devel/py-hg-evolve
DEPENDS+=	${PYPKGPREFIX}-mercurial>=6.8.1:../../devel/py-mercurial
DEPENDS+=	git-base>=2.47.1:../../devel/git-base
DEPENDS+=	git-cinnabar>=0.7.0beta1:../../devel/git-cinnabar
DEPENDS+=	git-perlscripts>=2.47.1:../../devel/git-perlscripts
DEPENDS+=	rsync>0:../../net/rsync

# For anonymous server -- consider splitting into a separate
# (meta-)package if we don't end up using this for the authenticated
# server.  Mainly so we don't have to bake py311-uwsgi, or py312-uwsgi,
# or, I mean, py314-uwsgi into the image build scripts...
DEPENDS+=	${PYPKGPREFIX}-acme-tiny>=0:../../security/py-acme-tiny
DEPENDS+=	${PYPKGPREFIX}-uwsgi>=0:../../www/py-uwsgi
DEPENDS+=	cgit>=0:../../www/cgit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cram>=0.7:../../devel/py-cram

USE_LANGUAGES=	c

PYTHON_SELF_CONFLICT=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	27

PYSETUPSUBDIR=	hghooks
USE_PYTEST=	no

REPLACE_PYTHON=	bin/syncd.py

MAKE_FLAGS+=	prefix=${PREFIX:Q}

INSTALL_MAKE_FLAGS+=	prefix=${PREFIX:Q}
INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share

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

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
