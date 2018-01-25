# $NetBSD$

DISTNAME=	pysmi-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysmi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/etingof/pysmi
COMMENT=	SNMP SMI/MIB Parser
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-ply-[0-9]*:../../devel/py-ply

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
