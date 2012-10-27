# $NetBSD: Makefile,v 1.9 2012/10/27 16:52:10 noud4 Exp $
#

DISTNAME=	Sumatra-0.3.0.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/S/s/S/.tar//}
PKGREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	http://pypi.python.org/packages/source/S/Sumatra/
EXTRACT_SUFX=	.gz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://neuralensemble.org/trac/sumatra/
COMMENT=	Tracking projects based on numerical simulation or analysis


DEPENDS+=	mercurial>=1.6:../../devel/mercurial
DEPENDS+=	scmgit-base>=1.7.0.5:../../devel/scmgit-base
DEPENDS+=	${PYPKGPREFIX}-subversion>=1.6.9:../../devel/py-subversion
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-tagging>=0.2.1:../../wip/py-django-tagging
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.6.0:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-mpi4py>=1.2.1:../../wip/py-mpich4py
DEPENDS+=	${PYPKGPREFIX}-genesis>=0:../../wip/py-genesis

WRKSRC=		${WRKDIR}/Sumatra-0.3.0
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PLIST_SUBST+=	THIS_EGG_INFODIR=${EGG_NAME:S|.tar||}-py${PYVERSSUFFIX}.egg-info

INSTALLATION_DIRS=	share/doc/py-sumatra

post-extract:
	${MV} ${WRKSRC}/bin/smt ${WRKSRC}/bin/smt${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/smtweb ${WRKSRC}/bin/smtweb${PYVERSSUFFIX}

do-test:
	${RUN} cd ${WRKSRC}; ${TEST_ENV} ${SH} test/unittests/all_tests.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/py-sumatra

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
