# $NetBSD$

DISTNAME=	jsbeautifier-1.6.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsbeautifier/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jsbeautifier.org/
COMMENT=	JavaScript unobfuscator and beautifier
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-editorconfig-core>=0.12.0:../../wip/py-editorconfig-core
DEPENDS+=	${PYPKGPREFIX}-six>=1.6.1:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
