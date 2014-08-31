# $NetBSD: Makefile,v 1.2 2014/08/31 17:23:04 heidnes Exp $

SVN_REVISION=	291592
DIST_VERSION=	0.1
ORIG_NAME=	depot_tools
DISTNAME=	${ORIG_NAME}-${DIST_VERSION}pre${SVN_REVISION}
PKGNAME=	chromium-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dev.chromium.org/developers/how-tos/install-depot-tools
COMMENT=	Chromium depot tools
LICENSE=	modified-bsd

USE_TOOLS+=	bash:run tar

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*bash[^ ]*
REPLACE.bash.new=	${PREFIX}/bin/bash
REPLACE_FILES.bash+=	apply_issue
REPLACE_FILES.bash+=	clang-format
REPLACE_FILES.bash+=	create-chromium-git-src
REPLACE_FILES.bash+=	download_from_google_storage
REPLACE_FILES.bash+=	drover
REPLACE_FILES.bash+=	fetch
REPLACE_FILES.bash+=	gcl
REPLACE_FILES.bash+=	gclient
REPLACE_FILES.bash+=	gclient_completion.sh
REPLACE_FILES.bash+=	gclient_scm.py
REPLACE_FILES.bash+=	git-cache
REPLACE_FILES.bash+=	git-cherry-pick-upload
REPLACE_FILES.bash+=	git-cl
REPLACE_FILES.bash+=	git-crsync
REPLACE_FILES.bash+=	git-crup
REPLACE_FILES.bash+=	git-freeze
REPLACE_FILES.bash+=	git-lkgr
REPLACE_FILES.bash+=	git-map
REPLACE_FILES.bash+=	git-map-branches
REPLACE_FILES.bash+=	git-mark-merge-base
REPLACE_FILES.bash+=	git-nav-downstream
REPLACE_FILES.bash+=	git-nav-upstream
REPLACE_FILES.bash+=	git-new-branch
REPLACE_FILES.bash+=	git-number
REPLACE_FILES.bash+=	git-rebase-update
REPLACE_FILES.bash+=	git-rename-branch
REPLACE_FILES.bash+=	git-reparent-branch
REPLACE_FILES.bash+=	git-retry
REPLACE_FILES.bash+=	git-runhooks
REPLACE_FILES.bash+=	git-squash-branch
REPLACE_FILES.bash+=	git-thaw
REPLACE_FILES.bash+=	git-try
REPLACE_FILES.bash+=	git-upstream-diff
REPLACE_FILES.bash+=	gn
REPLACE_FILES.bash+=	man/push_to_gs.sh
REPLACE_FILES.bash+=	man/src/*.sh
REPLACE_FILES.bash+=	ninja
REPLACE_FILES.bash+=	python_git_runner.sh
REPLACE_FILES.bash+=	roll-dep
REPLACE_FILES.bash+=	testing_support/*.sh
REPLACE_FILES.bash+=	tests/*.sh
REPLACE_FILES.bash+=	update_depot_tools

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing pkg path
SUBST_STAGE.path=	pre-build
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
REPLACE_PYTHON+=	git-cl-upload-hook
REPLACE_PYTHON+=	git_utils/git-tree-prune
REPLACE_PYTHON+=	repo
REPLACE_PYTHON+=	support/chromite_wrapper
REPLACE_PYTHON+=	tests/sample_pre_commit_hook
REPLACE_PYTHON+=	third_party/gsutil/gsutil
REPLACE_PYTHON+=	weekly
REPLACE_PYTHON+=	wtf

INSTALLATION_DIRS+=	share/chromium-depot_tools

do-configure:

do-build:

do-install:
	cd ${WRKSRC}; \
	tar cf - . | \
		(cd ${DESTDIR}/${PREFIX}/share/chromium-depot_tools; tar xf -)

.include "../../lang/python/tool.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
