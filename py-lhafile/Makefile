# $NetBSD: Makefile,v 1.1 2014/07/13 13:37:01 rhialto Exp $

DISTNAME=	python-lhafile
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}-0
CATEGORIES=	python

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	https://github.com/FrodeSolheim/python-lhafile
COMMENT=	Support (Amiga-style; bugfixed) LHA files
LICENSE=	modified-bsd

USE_LANGUAGES=	c
PYDISTUTILSPKG=	yes

GIT_REPOSITORIES=	github
GIT_REPO.github=	git://github.com/FrodeSolheim/python-lhafile.git
GIT_MODULE.github=	python-lhafile
# CHECKOUT_DATE=          2014-07-13  # This date is ok.

.include "../../lang/python/extension.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
