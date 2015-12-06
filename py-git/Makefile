# $NetBSD: Makefile,v 1.3 2014/12/31 13:58:32 thomasklausner Exp $

DISTNAME=	GitPython-0.3.2.RC1
PKGNAME=	${PYPKGPREFIX}-git-0.3.2.rc1
EGG_NAME=	${DISTNAME:S/.RC/rc/}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/G/GitPython/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://gitorious.org/projects/git-python/
COMMENT=	Python library used to interact with Git repositories
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-gitdb>=0.6.1:../../wip/py-gitdb

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.3.2.RC1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
