# $NetBSD$

DISTNAME=	swh.scheduler-0.8.2
PKGNAME=	${PYPKGPREFIX}-swh-scheduler-0.8.2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.scheduler/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/diffusion/DSCH/
COMMENT=	Software Heritage Scheduler
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-attrs>=19.3.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-celery>=4.3:../../net/py-celery
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-elasticsearch>5.4:../../databases/py-elasticsearch
DEPENDS+=	${PYPKGPREFIX}-flask>=0:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-humanize>=0:../../textproc/py-humanize
DEPENDS+=	${PYPKGPREFIX}-pika>=1.1.0:../../net/py-pika
#DEPENDS+=	${PYPKGPREFIX}-psycopg2>=0:../../databases/py-psycopg2
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-attrs-strict>=0.2.0:../../wip/py-attrs-strict
DEPENDS+=	${PYPKGPREFIX}-swh-core>=0.5:../../wip/py-swh-core
DEPENDS+=	${PYPKGPREFIX}-swh-storage>=0.11.1:../../wip/py-swh-storage

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
