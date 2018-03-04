# $NetBSD$

.include "../../mk/bsd.prefs.mk"

SCM_UNDER_TEST?=	# none; set by files/test
.if empty(SCM_UNDER_TEST)

DISTNAME=	mk-scm-tests-1.0
CATEGORIES=	pkgtools
PLIST_SRC=	# none
DISTFILES=	# none

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://www.pkgsrc.org/
COMMENT=	System tests for wip/mk infrastructure
LICENSE=	2-clause-bsd

NO_CHECKSUM=	yes
NO_BUILD=	yes
USE_TOOLS+=	bash

run-tests: .PHONY
	${BASH} files/test

do-install:
	${DO_NADA}

.else

DISTNAME=	pkgbase-1.0
CATEGORIES=	pkgtools
PLIST_SRC=	# none

.endif

.if ${SCM_UNDER_TEST} == cvs
CVS_ROOT=		${.CURDIR}/tmp/repo
CVS_REPOSITORIES=	2017 current
CVS_ROOT.2017=		${CVS_ROOT}
CVS_MODULE.2017=	${CVS_MODULE}
CVS_TAG.2017=		v2017
CVS_ROOT.current=	${CVS_ROOT}
CVS_MODULE.current=	${CVS_MODULE}
.include "../../wip/mk/cvs-package.mk"
.endif

.if ${SCM_UNDER_TEST} == fossil
FOSSIL_REPO=		${.CURDIR}/tmp/repo/pkgbase/pkgbase.fossil
FOSSIL_REPOSITORIES=	2017 current
FOSSIL_REPO.2017=	${FOSSIL_REPO}
FOSSIL_VERSION.2017=	v2017
FOSSIL_REPO.current=	${FOSSIL_REPO}
.include "../../wip/mk/fossil-package.mk"
.endif

.if ${SCM_UNDER_TEST} == git
GIT_REPO=		${.CURDIR}/tmp/repo/pkgbase
GIT_REPOSITORIES=	2017 current
GIT_REPO.2017=		${GIT_REPO}
GIT_TAG.2017=		v2017
GIT_REPO.current=	${GIT_REPO}
.include "../../wip/mk/git-package.mk"
.endif

.if ${SCM_UNDER_TEST} == hg
HG_REPO=	${.CURDIR}/tmp/repo/pkgbase
HG_REPOSITORIES=	2017 current
HG_REPO.2017=		${HG_REPO}
HG_TAG.2017=		v2017
HG_REPO.current=	${HG_REPO}
.include "../../wip/mk/hg-package.mk"
.endif

.if ${SCM_UNDER_TEST} == svn
SVN_REPO=		file://${.CURDIR}/tmp/repo/pkgbase/trunk
SVN_REPOSITORIES=	2017 current
SVN_REPO.2017=		${SVN_REPO}
SVN_REVISION.2017=	1
SVN_REPO.current=	${SVN_REPO}
.include "../../wip/mk/svn-package.mk"
.endif

.include "../../mk/bsd.pkg.mk"
