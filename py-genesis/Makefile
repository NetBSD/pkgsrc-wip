# $NetBSD: Makefile,v 1.1 2012/08/17 18:03:26 slitvinov Exp $
#

DISTNAME=	genesis-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python
MASTER_SITES=	http://pypi.python.org/packages/source/g/genesis/

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/genesis
COMMENT=	Run Genesis on a copy of a project template to create a new project
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
