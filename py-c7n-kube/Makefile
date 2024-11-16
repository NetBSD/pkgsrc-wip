# $NetBSD: Makefile,v 1.13 2023/06/06 12:42:49 riastradh Exp $

DISTNAME=	c7n-0.9.42.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/c7n/c7n-kube/:S/0.9.42.0/0.2.41/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=cloud-custodian/}
GITHUB_PROJECT=	cloud-custodian

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cloudcustodian.io/
COMMENT=	Cloud Custodian Kubernetes Support
LICENSE=	apache-2.0

WHEEL_NAME=	c7n_kube-${PKGVERSION_NOREV}

# FIXME: we should not hardcode version here!
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-0.9.42.0/tools/c7n_kube

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-c7n-[0-9]*:../../wip/py-c7n
DEPENDS+=	${PYPKGPREFIX}-jsonpatch>=1.32:../../wip/py-jsonpatch
DEPENDS+=	${PYPKGPREFIX}-kubernetes>=10.0.1:../../sysutils/py-kubernetes

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/c7n-kates ${DESTDIR}${PREFIX}/bin/c7n-kates${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/c7n-kube ${DESTDIR}${PREFIX}/bin/c7n-kube${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
