# $NetBSD$

DISTNAME=	collectd-haproxy-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
GITHUB_PROJECT=	collectd-haproxy
MASTER_SITES=	${MASTER_SITE_GITHUB:=wglass/}
GITHUB_TAG=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/wglass/collectd-haproxy
COMMENT=	Plugin for collectd to gather HAProxy metrics
LICENSE=	mit

DEPENDS+=       haproxy>=1.4:../../net/haproxy
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-collectd-[0-9]*:../../sysutils/py-collectd


.include "../../mk/bsd.prefs.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
