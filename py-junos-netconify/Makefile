# $NetBSD$

DISTNAME=	py-junos-netconify-1.0.2
PKGNAME=	${DISTNAME:S/py-/${PYPKGPREFIX}-/}
CATEGORIES=	net
MASTER_SITES=	-https://github.com/Juniper/${PKGBASE}/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}
EGG_NAME=	${DISTNAME:S/^py-//:S/-/_/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Juniper/${PKGBASE}
COMMENT=	Junos console/bootstrap automation Python module
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSUFFIX=${PYVERSUFFIX}
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
PYTHON_VERSIONS_ACCEPTED=	27 26

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
