# $NetBSD: Makefile,v 1.3 2014/09/01 11:00:08 fhajny Exp $

GIT_REVISION=	75c2cc859d3547a02edff5387ec75d47ed41afd5
DISTNAME=	${GIT_REVISION}
PKGNAME=	chromium-depot_tools-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://chromium.googlesource.com/chromium/tools/depot_tools.git/+archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dev.chromium.org/developers/how-tos/install-depot-tools
COMMENT=	Chromium depot tools
LICENSE=	modified-bsd

USE_TOOLS+=	bash:run tar pax:build

REPLACE_BASH+=	apply_issue
REPLACE_BASH+=	bootstrap/win/git-bash.template.sh
REPLACE_BASH+=	bootstrap/win/profile.d.python.sh
REPLACE_BASH+=	cit
REPLACE_BASH+=	clang-format
REPLACE_BASH+=	commit_queue
REPLACE_BASH+=	create-chromium-git-src
REPLACE_BASH+=	depot-tools-auth
REPLACE_BASH+=	download_from_google_storage
REPLACE_BASH+=	drover
REPLACE_BASH+=	fetch
REPLACE_BASH+=	gcl
REPLACE_BASH+=	gclient
REPLACE_BASH+=	gclient_completion.sh
REPLACE_BASH+=	gclient_scm.py
REPLACE_BASH+=	git-auto-svn
REPLACE_BASH+=	git-cache
REPLACE_BASH+=	git-cherry-pick-upload
REPLACE_BASH+=	git-cl
REPLACE_BASH+=	git-crrev-parse
REPLACE_BASH+=	git-crsync
REPLACE_BASH+=	git-drover
REPLACE_BASH+=	git-find-releases
REPLACE_BASH+=	git-footers
REPLACE_BASH+=	git-freeze
REPLACE_BASH+=	git-hyper-blame
REPLACE_BASH+=	git-map
REPLACE_BASH+=	git-map-branches
REPLACE_BASH+=	git-mark-merge-base
REPLACE_BASH+=	git-nav-downstream
REPLACE_BASH+=	git-nav-upstream
REPLACE_BASH+=	git-new-branch
REPLACE_BASH+=	git-number
REPLACE_BASH+=	git-rebase-update
REPLACE_BASH+=	git-rename-branch
REPLACE_BASH+=	git-reparent-branch
REPLACE_BASH+=	git-retry
REPLACE_BASH+=	git-runhooks
REPLACE_BASH+=	git-squash-branch
REPLACE_BASH+=	git-thaw
REPLACE_BASH+=	git-try
REPLACE_BASH+=	git-upstream-diff
REPLACE_BASH+=	gn
REPLACE_BASH+=	man/push_to_gs.sh
REPLACE_BASH+=	man/src/*.sh
REPLACE_BASH+=	ninja
REPLACE_BASH+=	roll-dep
REPLACE_BASH+=	roll-dep-svn
REPLACE_BASH+=	testing_support/*.sh
REPLACE_BASH+=	tests/*.sh
REPLACE_BASH+=	update_depot_tools

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing pkg path
SUBST_STAGE.path=	post-extract
SUBST_FILES.path+=	man/src/make_docs.sh
SUBST_FILES.path+=	third_party/boto/services/sonofmmm.py
SUBST_SED.path+=	-e 's:/usr/local/:${PREFIX}/:'

REPLACE_PYTHON+=	*.py
REPLACE_PYTHON+=	*/*.py
REPLACE_PYTHON+=	*/*/*.py
REPLACE_PYTHON+=	*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*.py
REPLACE_PYTHON+=	cbuildbot
REPLACE_PYTHON+=	chrome_set_ver
REPLACE_PYTHON+=	cros
REPLACE_PYTHON+=	cros_sdk
REPLACE_PYTHON+=	repo
REPLACE_PYTHON+=	support/chromite_wrapper
REPLACE_PYTHON+=	tests/sample_pre_commit_hook
REPLACE_PYTHON+=	third_party/gsutil/gsutil
REPLACE_PYTHON+=	weekly
REPLACE_PYTHON+=	wtf

SUBST_CLASSES+=		pypath
SUBST_MESSAGE.pypath=	Fixing Python path
SUBST_STAGE.pypath=	post-extract
SUBST_FILES.pypath+=	apply_issue
SUBST_FILES.pypath+=	cit
SUBST_FILES.pypath+=	clang-format
SUBST_FILES.pypath+=	commit_queue
SUBST_FILES.pypath+=	fetch
SUBST_FILES.pypath+=	gcl
SUBST_FILES.pypath+=	depot-tools-auth
SUBST_FILES.pypath+=	download_from_google_storage
SUBST_FILES.pypath+=	drover
SUBST_FILES.pypath+=	gclient
SUBST_FILES.pypath+=	git-runhooks
SUBST_FILES.pypath+=	gn
SUBST_FILES.pypath+=	roll-dep
SUBST_FILES.pypath+=	roll-dep-svn
SUBST_SED.pypath+=	-e 's:exec python:exec ${PYTHONBIN}:'

INSTALLATION_DIRS+=	share/chromium-depot_tools

NO_BUILD=	yes

EXTRACT_DIR=	${WRKDIR}/${DISTNAME}

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}/${PREFIX}/share/chromium-depot_tools

.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
