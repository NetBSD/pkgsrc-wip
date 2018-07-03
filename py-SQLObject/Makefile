# $NetBSD: Makefile,v 1.13 2014/05/09 07:38:44 thomasklausner Exp $

DISTNAME=	SQLObject-1.3.1.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
EGG_NAME=	${DISTNAME:S|.tar||:Q}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SQLObject/}
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sqlobject.sourceforge.net/
COMMENT=	Allows you to translate RDBMS table rows into Python objects
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME:S|.tar||}
USE_LANGUAGES=	# none

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PLIST_SUBST+=		EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-mxDateTime

.include "options.mk"

.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
