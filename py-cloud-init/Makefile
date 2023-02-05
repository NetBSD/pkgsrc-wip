# $NetBSD$

DISTNAME=	cloud-init-22.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=canonical/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cloud-init.io/
COMMENT=	Industry-standard cloud instance initialization
LICENSE=	gnu-gpl-3 OR apache-2.0

USE_TOOLS+=	gmake

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-oauthlib-[0-9]*:../../security/py-oauthlib
DEPENDS+=	${PYPKGPREFIX}-serial-[0-9]*:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-jsonschema-[0-9]*:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-netifaces>=0.10.4:../../net/py-netifaces
# for testing:
DEPENDS+=	${PYPKGPREFIX}-responses-[0-9]*:../../net/py-responses
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock

# WIP pkgs:
DEPENDS+=	${PYPKGPREFIX}-jsonpatch-[0-9]*:../../wip/py-jsonpatch

MAKE_ENV+=	VARIANT=${OPSYS:tl}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
