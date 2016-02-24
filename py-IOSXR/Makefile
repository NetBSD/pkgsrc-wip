# $NetBSD$

DISTNAME=	py-IOSXR-0.12
PKGNAME=	${DISTNAME:S/py-/${PYPKGPREFIX}-/}
CATEGORIES=	net
MASTER_SITES=	-https://github.com/fooelisa/pyiosxr/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}
EGG_NAME=	${DISTNAME:S/-//}

WRKSRC=		${WRKDIR}/${DISTNAME:S/-//:tl}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fooelisa/${PKGBASE}
COMMENT=	Library for interacting with IOS-XR routers
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect

USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSUFFIX=${PYVERSUFFIX}
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
PYTHON_VERSIONS_ACCEPTED=	27 26

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
