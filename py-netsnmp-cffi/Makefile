# $NetBSD$

DISTNAME=	netsnmp-cffi-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Uninett/}
GITHUB_PROJECT=	netsnmp-cffi

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://github.com/Uninett/netsnmp-cffi
COMMENT=	CFFI-based python interface to net-snmp
LICENSE=	apache-2.0

USE_LANGUAGES+=	c
# Needs python >= 39
PYTHON_VERSIONS_INCOMPATIBLE+=	27

MAKE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.1:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi

.include "../../mk/bsd.prefs.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
