# $NetBSD$

DISTNAME=	pysnmp-6.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysnmp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/etingof/pysnmp
COMMENT=	SNMP library for Python
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.2.3:../../security/py-asn1
#DEPENDS+=	${PYPKGPREFIX}-cryptodomex-[0-9]*:../../wip/py-cryptodomex
DEPENDS+=	${PYPKGPREFIX}-smi-[0-9]*:../../wip/py-smi

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
