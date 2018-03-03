# $NetBSD$

DISTNAME=	pkgbase-1.0
CATEGORIES=	pkgtools
PLIST_SRC=	# none

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://www.pkgsrc.org/
COMMENT=	System tests for wip/mk infrastructure
LICENSE=	2-clause-bsd

SCM_UNDER_TEST?=	# none; is set by files/test

.if empty(SCM_UNDER_TEST)
DISTNAME=	mk-scm-tests-1.0
DISTFILES=	# none
NO_CHECKSUM=	yes
NO_BUILD=	yes
USE_TOOLS+=	bash

run-tests: .PHONY
	${BASH} files/test

do-install:
	${DO_NADA}
.endif

.include "../../mk/bsd.prefs.mk"

.if ${SCM_UNDER_TEST} == cvs
CVS_ROOT=	${.CURDIR}/tmp/repo
.include "../../wip/mk/cvs-package.mk"
.endif

.if ${SCM_UNDER_TEST} == fossil
FOSSIL_REPO=	${.CURDIR}/tmp/repo/pkgbase/pkgbase.fossil
.include "../../wip/mk/fossil-package.mk"
.endif

.if ${SCM_UNDER_TEST} == git
GIT_REPO=	${.CURDIR}/tmp/repo/pkgbase
.include "../../wip/mk/git-package.mk"
.endif

.if ${SCM_UNDER_TEST} == hg
HG_REPO=	${.CURDIR}/tmp/repo/pkgbase
.include "../../wip/mk/hg-package.mk"
.endif

.if ${SCM_UNDER_TEST} == svn
SVN_REPO=	file://${.CURDIR}/tmp/repo/pkgbase/trunk
.include "../../wip/mk/svn-package.mk"
.endif

.include "../../mk/bsd.pkg.mk"
