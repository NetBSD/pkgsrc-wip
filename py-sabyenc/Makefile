# $NetBSD: Makefile,v 1.6 2015/02/04 10:10:53 thomasklausner Exp $

DISTNAME=	sabyenc-${DISTVERSION}
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
DISTVERSION=	3.3.6
CATEGORIES=	news
GIT_REPO=	https://github.com/sabnzbd/sabyenc.git
GIT_REVISION=	f0b4934a740549afcea8bc677d4bd9e42c179838  # 22 June 2019
CHECKOUT_DATE=	2019-06-22
#GITHUB_PROJECT= sabnzbd
GIT_BRANCH=	sabyenc-python2

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://sabnzbd.org
COMMENT=	Web-interface based binary newsgrabber in python, with nzb support
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND modified-bsd AND mit

PYDISTUTILSPKG=YES
USE_LANGUAGES+=	c

# This branch is python 2.7 only, because sabnzbd is limited to that, due to another dependency.
PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/extension.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
