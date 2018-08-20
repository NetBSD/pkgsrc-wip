# $NetBSD$

DISTNAME=	3dsconv-4.2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=ihaveamac/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ihaveamac/3dsconv/
COMMENT=	Script to convert Nintendo 3DS CCI (".cci", ".3ds") files to the CIA format
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-aes-[0-9]*:../../security/py-aes

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	3dsconv/3dsconv.py

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
