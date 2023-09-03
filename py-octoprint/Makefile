# $NetBSD: Makefile,v 1.7 2022/01/05 15:41:19 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-octoprint-1.9.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=OctoPrint/}
GITHUB_PROJECT=	OctoPrint
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/OctoPrint/OctoPrint/
COMMENT=	Snappy web interface for 3D printers
LICENSE=	gnu-agpl-v3

RCD_SCRIPTS=	octoprint

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-blinker>=1.6.1:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-cachelib>=0.10.2:../../devel/py-cachelib
DEPENDS+=	${PYPKGPREFIX}-click>=8.1.3:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-colorlog>=6.7.0:../../devel/py-colorlog
DEPENDS+=	${PYPKGPREFIX}-emoji>=2.2.0:../../converters/py-emoji
DEPENDS+=	${PYPKGPREFIX}-feedparser>=6.0.10:../../textproc/py-feedparser
DEPENDS+=	${PYPKGPREFIX}-filetype>=1.2.0:../../sysutils/py-filetype
DEPENDS+=	${PYPKGPREFIX}-flask>=2.2.3:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-assets>=2.0:../../www/py-flask-assets
DEPENDS+=	${PYPKGPREFIX}-flask-babel>=3.1.0:../../www/py-flask-babel
DEPENDS+=	${PYPKGPREFIX}-flask-login>=0.6.2:../../www/py-flask-login
DEPENDS+=	${PYPKGPREFIX}-future>=0.18.3:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-markdown>=3.4.3:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-netaddr>=0.8:../../net/py-netaddr
DEPENDS+=	${PYPKGPREFIX}-netifaces>=0.11:../../net/py-netifaces
DEPENDS+=	${PYPKGPREFIX}-octoprint-filecheck>=2021.2.23:../../print/py-octoprint-filecheck
DEPENDS+=	${PYPKGPREFIX}-octoprint-firmwarecheck>=2021.10.11:../../print/py-octoprint-firmwarecheck
DEPENDS+=	${PYPKGPREFIX}-octoprint-pisupport>=2023.5.24:../../print/py-octoprint-pisupport
DEPENDS+=	${PYPKGPREFIX}-pkginfo>=1.9.6:../../devel/py-pkginfo
DEPENDS+=	${PYPKGPREFIX}-psutil>=5.9.4:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-pydantic>=1.10.7:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-pylru>=1.2.1:../../devel/py-pylru
DEPENDS+=	${PYPKGPREFIX}-regex>2018.11.6:../../textproc/py-regex
DEPENDS+=	${PYPKGPREFIX}-requests>=2.28.2:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-sarge>=0.1.7:../../devel/py-sarge
DEPENDS+=	${PYPKGPREFIX}-semantic_version>=2.10.0:../../devel/py-semantic_version
DEPENDS+=	${PYPKGPREFIX}-serial>=3.5:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-sentry-sdk>=1.19.1:../../devel/py-sentry-sdk
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.2:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-Unidecode>=0.04.14:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-watchdog>=2.3.1:../../sysutils/py-watchdog
DEPENDS+=	${PYPKGPREFIX}-websocket-client>=1.5.1:../../www/py-websocket-client
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=2.2.3:../../www/py-werkzeug
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.15:../../devel/py-wrapt
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-zeroconf>=0.39.4:../../net/py-zeroconf
DEPENDS+=	${PYPKGPREFIX}-zipstream-ng>=1.6.0:../../archivers/py-zipstream-ng

#.include "../../mk/bsd.prefs.mk"
#
#.if ${OPSYS} == "Darwin"
#DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.4:../../devel/py-appdirs
#.endif

USE_PKG_RESOURCES=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/octoprint \
		${DESTDIR}${PREFIX}/bin/octoprint-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
