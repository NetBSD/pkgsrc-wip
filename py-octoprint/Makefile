# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-octoprint-1.3.11
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
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.8.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pkginfo>=1.5.0.1:../../devel/py-pkginfo
DEPENDS+=	${PYPKGPREFIX}-requests>=2.21.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-rsa>=4.0:../../security/py-rsa
DEPENDS+=	${PYPKGPREFIX}-serial>=3.4:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-sentry-sdk=0.7.7:../../wip/py-sentry-sdk
DEPENDS+=	${PYPKGPREFIX}-typing>=3.6.6:../../devel/py-typing
DEPENDS+=	${PYPKGPREFIX}-watchdog>=0.9.0:../../sysutils/py-watchdog
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=0.15.1:../../www/py-werkzeug

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
