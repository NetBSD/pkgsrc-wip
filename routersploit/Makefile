# $NetBSD: Makefile,v 1.4 2017/09/14 12:43:54 leot Exp $

DISTNAME=	routersploit-3.4.0
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_GITHUB:=threat9/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/threat9/routersploit
COMMENT=	Exploitation Framework for Embedded Devices
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-snmp-[0-9]*:../../wip/py-snmp

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	rsf.py

# Only for Python 3.x but still not ported to 3.8
PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
