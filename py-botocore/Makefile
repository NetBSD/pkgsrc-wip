# $NetBSD$

GITHUB_PROJECT=	botocore
DISTNAME=	${GITHUB_PROJECT}-1.4.65
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=boto/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://github.com/boto/
COMMENT=	Low-level interface to a growing number of Amazon Web Services
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-jmespath>=0.9.0:../../wip/py-jmespath
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.5.3:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-doctutils>=0.12:../../textproc/py-docutils

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

DOCDIR=		${PREFIX}/share/doc/botocore

WRKSRC=		${WRKDIR}/${DISTNAME}

post-build:
		cd ${WRKSRC}/docs/ && make SPHINXBUILD=${PREFIX}/bin/sphinx-build${PYVERSSUFFIX} man

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
