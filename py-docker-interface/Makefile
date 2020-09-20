# $NetBSD$

DISTNAME=	docker_interface-0.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysuitls python
MASTER_SITES=	https://files.pythonhosted.org/packages/70/ee/33189ac031ef7b4d4a9eecf5a2ecd50d686ac56fc34f1695ef43791a25e6/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/spotify/docker_interface
COMMENT=	Building images and running commands using Docker
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-jsonschema>=3.2.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
