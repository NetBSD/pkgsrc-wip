# $NetBSD: Makefile,v 1.4 2017/09/14 12:43:54 leot Exp $

DISTNAME=	routersploit-3.3.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=threat9/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/threat9/routersploit
COMMENT=	Exploitation Framework for Embedded Devices
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto
DEPENDS+=	${PYPKGPREFIX}-snmp-[0-9]*:../../wip/py-snmp

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	rsf.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

#
# - Add a MANIFEST.in in order to install all routersploit/resources package
#   data files
# - Add an (empty) __init__.py in order to correctly pick up Python code in
#   routersploit/resources subdirectories
#
# Shared upstream via <https://github.com/threat9/routersploit/pull/494>
#
post-extract:
	${CP} ${FILESDIR}/MANIFEST.in ${WRKSRC}
	${RUN} cd ${WRKSRC} && ${TOUCH} routersploit/resources/__init__.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
