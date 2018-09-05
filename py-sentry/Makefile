# $NetBSD: Makefile,v 1.1 2015/01/14 21:18:37 jihbed Exp $

DISTNAME=	sentry-8.22.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sentry/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://www.getsentry.com/
COMMENT=	Realtime logging and aggregation server
LICENSE=	modified-bsd

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

DEPENDS+=	${PYPKGPREFIX}-boto3>=1.6.2:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-botocore>=1.1.6:../../devel/py-enum34
DEPENDS+=	${PYPKGPREFIX}-botocore>=1.9.2:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-celery>=4.1.0:../../net/py-celery
DEPENDS+=	${PYPKGPREFIX}-click>=6.7:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-cssutils>=1.0.2:../../textproc/py-cssutils
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.7.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-django>=1.11.11:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-crispy-forms>=1.7.2:../../wip/py-django-crispy-forms
DEPENDS+=	${PYPKGPREFIX}-django-jsonfield>=1.0.1:../../wip/py-django-jsonfield
DEPENDS+=	${PYPKGPREFIX}-django-picklefield>=1.0.0:../../wip/py-django-picklefield
DEPENDS+=	${PYPKGPREFIX}-django-sudo>=2.1.0:../../wip/py-django-sudo
DEPENDS+=	${PYPKGPREFIX}-django-templatetag-sugar>=1.0:../../wip/py-django-templatetag-sugar
DEPENDS+=	${PYPKGPREFIX}-djangorestframework>=3.7.7:../../www/py-djangorestframework
DEPENDS+=	${PYPKGPREFIX}-email-reply-parser>=0.1.1:../../wip/py-email-reply-parser
DEPENDS+=	${PYPKGPREFIX}-exam>=0.10.6:../../devel/py-exam
DEPENDS+=	${PYPKGPREFIX}-hiredis>=0.2.0:../../wip/py-hiredis
DEPENDS+=	${PYPKGPREFIX}-honcho>=1.0.1:../../wip/py-honcho
DEPENDS+=	${PYPKGPREFIX}-ipaddress>=1.0.19:../../net/py-ipaddress
DEPENDS+=	${PYPKGPREFIX}-kombu>=4.1.0:../../net/py-kombu
DEPENDS+=	${PYPKGPREFIX}-loremipsum>=1.0.5:../../textproc/py-loremipsum
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.2.1:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-memcached>=1.59:../../devel/py-memcached
DEPENDS+=	${PYPKGPREFIX}-mmh3>=2.5.1:../../wip/py-mmh3
DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-openid>=2.2.5:../../security/py-openid
DEPENDS+=	${PYPKGPREFIX}-Pillow>=5.0.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-percy>=1.1.2:../../wip/py-percy
DEPENDS+=	${PYPKGPREFIX}-petname>=2.2:../../wip/py-petname
DEPENDS+=	${PYPKGPREFIX}-progressbar2>=3.6.0:../../wip/py-progressbar2
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2.7.4:../../databases/py-psycopg2
DEPENDS+=	${PYPKGPREFIX}-pyaml>=17.12.1:../../textproc/py-pyaml
DEPENDS+=	${PYPKGPREFIX}-qrcode>=5.3:../../graphics/py-qrcode
DEPENDS+=	${PYPKGPREFIX}-raven>=6.6.0:../../www/py-raven
DEPENDS+=	${PYPKGPREFIX}-rb>=1.7:../../wip/py-rb
DEPENDS+=	${PYPKGPREFIX}-redis-cluster>=1.3.4:../../wip/py-redis-cluster
DEPENDS+=	${PYPKGPREFIX}-redis>=2.10.6:../../databases/py-redis
DEPENDS+=	${PYPKGPREFIX}-requests>=2.18.4:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-selenium>=3.11.0:../../www/py-selenium
DEPENDS+=	${PYPKGPREFIX}-setproctitle>=1.1.10:../../sysutils/py-setproctitle
DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.13.0:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-six>=1.11.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-sqlparse>=0.2.4:../../databases/py-sqlparse
DEPENDS+=	${PYPKGPREFIX}-statsd>=3.2.2:../../wip/py-statsd
DEPENDS+=	${PYPKGPREFIX}-structlog>=18.1.0:../../sysutils/py-structlog
DEPENDS+=	${PYPKGPREFIX}-symbolic>=5.0.1:../../wip/py-symbolic
DEPENDS+=	${PYPKGPREFIX}-test-django>=3.1.2:../../www/py-test-django
DEPENDS+=	${PYPKGPREFIX}-test-html>=1.17.0:../../wip/py-test-html
DEPENDS+=	${PYPKGPREFIX}-test-metadata>=1.7.0:../../wip/py-test-metadata
DEPENDS+=	${PYPKGPREFIX}-test>=3.5.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-toronado>=0.0.11:../../wip/py-toronado
DEPENDS+=	${PYPKGPREFIX}-u2flib-server>=5.0.0:../../wip/py-u2flib-server
DEPENDS+=	${PYPKGPREFIX}-ua-parser>=0.8.0:../../wip/py-ua-parser
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.22:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-uwsgi>=2.0.17:../../www/py-uwsgi

PYTHON_VERSIONS_ACCEPTED=	27  # py-openid

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
