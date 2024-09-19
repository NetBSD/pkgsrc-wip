# $NetBSD: Makefile,v 1.16 2013/12/31 18:29:37 othyro Exp $
#

DISTNAME=	pycsp-0.9.2
GITHUB_PROJECT=	pycsp
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=runefriborg/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/pycsp/
COMMENT=	Brings CSP (communicating sequential processes) to Python
LICENSE=	mit

EGDIR=			${PREFIX}/share/examples/py-csp
EGG_NAME=		${DISTNAME:S/-complete//1}
INSTALLATION_DIRS+=	${EGDIR}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	test/runtests.sh
SUBST_MESSAGE.prefix=	Fixing Python's path
SUBST_SED.prefix=	-e "s|PYTHON=python|PYTHON=${PYTHONBIN}|1"

post-install:
	${INSTALL_DATA} ${WRKSRC}/test/*.py ${DESTDIR}${EGDIR}

do-test:
	${RUN} cd ${WRKSRC}/test && \
		${SETENV} ${TEST_ENV} \
		PYTHONPATH=${DESTDIR}${PREFIX}/${PYSITELIB} \
		./runtests.sh

DEPENDS+=	${PYPKGPREFIX}-Pyro4-[0-9]*:../../devel/py-Pyro
DEPENDS+=	${PYPKGPREFIX}-greenlet-[0-9]*:../../devel/py-greenlet
DEPENDS+=	${PYPKGPREFIX}-uuid-[0-9]*:../../wip/py-uuid
DEPENDS+=	${PYPKGPREFIX}-netifaces-[0-9]*:../../net/py-netifaces
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
