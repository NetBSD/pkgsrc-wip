# $NetBSD: Makefile,v 1.29 2020/05/03 18:29:16 adam Exp $

DISTNAME=	cherry_picker-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cherry_picker/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/cherry_picker/
COMMENT=	Backport CPython changes from main to maintenance branches
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-click>=6.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-gidgethub-[0-9]*:../../devel/py-gidgethub
DEPENDS+=	${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	git-base-[0-9]*:../../devel/git-base
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

# as of 2.1.0
# 15 failed, 45 passed
# (or 14 if cherry_picker is installed first)
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
