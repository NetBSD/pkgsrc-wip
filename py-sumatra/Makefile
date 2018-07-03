# $NetBSD: Makefile,v 1.15 2014/05/09 07:38:50 thomasklausner Exp $

VER=		0.5.2
DISTNAME=	Sumatra-${VER}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/S/s/}
PKGREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Sumatra/}

MAINTAINER=	jihbed.research@gmail.com
COMMENT=	Tracking projects based on numerical simulation or analysis
HOMEPAGE=	http://neuralensemble.org/trac/sumatra/
# The name of the licence is CeCILL [1] but it is GNU GPL v2 compatible [2]
# [1] see work/Sumatra-0.4.0/COPYING
# [2] http://projects.opensource.org/pipermail/license-review/2012-February/000269.html
LICENSE=	gnu-gpl-v2

DEPENDS+=	mercurial>=1.6:../../devel/mercurial
DEPENDS+=	git-base>=1.7.0.5:../../devel/git-base
DEPENDS+=	${PYPKGPREFIX}-subversion>=1.6.9:../../devel/py-subversion
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-tagging>=0.2.1:../../www/py-django-tagging
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.6.0:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-mpi4py>=1.2.1:../../wip/py-mpi4py
DEPENDS+=	${PYPKGPREFIX}-genesis-[0-9]*:../../wip/py-genesis

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-django-tagging

INSTALLATION_DIRS=	share/doc/py-sumatra

post-extract:
	${MV} ${WRKSRC}/bin/smt ${WRKSRC}/bin/smt${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/smtweb ${WRKSRC}/bin/smtweb${PYVERSSUFFIX}

# test requires devel/py-coverage
do-test:
	${RUN} cd ${WRKSRC}/test/unittests; ${TEST_ENV} ${SH} all_tests.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/py-sumatra

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
