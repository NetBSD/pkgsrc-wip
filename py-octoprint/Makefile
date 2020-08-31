# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-octoprint-1.3.12
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=foosel/}
GITHUB_PROJECT=	OctoPrint
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/foosel/OctoPrint/
COMMENT=	Snappy web interface for 3D printers
LICENSE=	gnu-agpl-v3

PYTHON_VERSIONS_ACCEPTED=	27

#TODO register the remaining dependencies (see https://github.com/foosel/OctoPrint/blob/master/setup.py#L19)
DEPENDS+=	${PYPKGPREFIX}-awesome-slugify>=1.6.5:../../wip/py-awesome-slugify
DEPENDS+=	${PYPKGPREFIX}-cachelib>=0.1:../../wip/py-cachelib
DEPENDS+=	${PYPKGPREFIX}-chainmap>=1.0.3:../../wip/py-chainmap
DEPENDS+=	${PYPKGPREFIX}-emoji>=0.5.1:../../converters/py-emoji
DEPENDS+=	${PYPKGPREFIX}-feedparser>=5.2.1:../../textproc/py-feedparser
DEPENDS+=	${PYPKGPREFIX}-filetype>=1.0.5:../../wip/py-filetype
DEPENDS+=	${PYPKGPREFIX}-flask>=0.10.1:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-assets>=0.12:../../www/py-flask-assets
DEPENDS+=	${PYPKGPREFIX}-flask-babel>=0.12:../../www/py-flask-babel
DEPENDS+=	${PYPKGPREFIX}-flask-login>=0.2.11:../../www/py-flask-login
DEPENDS+=	${PYPKGPREFIX}-flask-principal>=0.4:../../www/py-flask-principal
DEPENDS+=	${PYPKGPREFIX}-frozendict>=1.2:../../devel/py-frozendict
DEPENDS+=	${PYPKGPREFIX}-future>=0.17.1:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-futures>=3.2:../../devel/py-futures
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.8.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markdown>=3.0:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-monotonic>=1.5:../../time/py-monotonic
DEPENDS+=	${PYPKGPREFIX}-netaddr>=0.7.19:../../net/py-netaddr
DEPENDS+=	${PYPKGPREFIX}-netifaces>=0.10.9:../../net/py-netifaces
DEPENDS+=	${PYPKGPREFIX}-pkginfo>=1.5.0.1:../../devel/py-pkginfo
DEPENDS+=	${PYPKGPREFIX}-psutil>=5.6.1:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-pylru>=1.2.0:../../wip/py-pylru
DEPENDS+=	${PYPKGPREFIX}-regex>2018.11.6:../../textproc/py-regex
DEPENDS+=	${PYPKGPREFIX}-requests>=2.21.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-rsa>=4.0:../../security/py-rsa
DEPENDS+=	${PYPKGPREFIX}-sarge>=0.1.5:../../wip/py-sarge
DEPENDS+=	${PYPKGPREFIX}-scandir>=1.10:../../devel/py-scandir
DEPENDS+=	${PYPKGPREFIX}-semantic_version>=2.6:../../devel/py-semantic_version
DEPENDS+=	${PYPKGPREFIX}-serial>=3.4:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-sentry-sdk>=0.7.7:../../wip/py-sentry-sdk
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.5.3:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-typing>=3.6.6:../../devel/py-typing
DEPENDS+=	${PYPKGPREFIX}-watchdog>=0.9.0:../../sysutils/py-watchdog
DEPENDS+=	${PYPKGPREFIX}-websocket-client>=0.56:../../www/py-websocket-client
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=0.15.1:../../www/py-werkzeug
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.11.1:../../devel/py-wrapt

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
