# $NetBSD: Makefile,v 1.10 2012/06/12 15:10:40 uccwen Exp $
#

DISTNAME=	SQLObject-1.3.1.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
EGG_NAME=	${DISTNAME:S|.tar||:Q}
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/S/SQLObject/
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sqlobject.sourceforge.net/
COMMENT=	Allows you to translate RDBMS table rows into Python objects
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME:S|.tar||:Q}
USE_LANGUAGES=	# none

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PLIST_SUBST+=		EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

.include "options.mk"

.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
