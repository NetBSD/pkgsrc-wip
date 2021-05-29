# $NetBSD$

DISTNAME=	kb-manager-0.1.6
EGGNAME=	${DISTNAME:S/-manager//}
PKGNAME=	${PYPKGPREFIX}-${EGGNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kb-manager/}

MAINTAINER=	nebbionegiuseppe@gmail.com
HOMEPAGE=	https://github.com/gnebbia/kb/
COMMENT=	Minimalist command line knowledge base manager
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-attrs>=0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-colored>=0:../../textproc/py-colored
DEPENDS+=	${PYPKGPREFIX}-gitpython>=0:../../devel/py-gitpython
DEPENDS+=	${PYPKGPREFIX}-sqlite3>=0:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-toml>=0:../../textproc/py-toml

PYTHON_VERSIONS_INCOMPATIBLE=	27 36 37

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
