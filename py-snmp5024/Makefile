# $NetBSD$

DISTNAME=	pysnmp5024-5.0.24
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GITHUB:=pysnmp/}
GITHUB_PROJECT=	pysnmp
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://github.com/pysnmp/pysnmp
COMMENT=	SNMP library for Python fixed to older version
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.2.3:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-smi-[0-9]*:../../wip/py-smi

CONFLICTS+=	${PYPKGPREFIX}-snmp-[0-9]*

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
