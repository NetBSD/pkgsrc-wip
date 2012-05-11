# $NetBSD: Makefile,v 1.9 2012/05/11 12:48:40 noud4 Exp $
#

DISTNAME=	SQLObject-0.12.2.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
EGG_NAME=	${DISTNAME:S|.tar||:Q}
PKGREVISION=	3
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/S/SQLObject/
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sqlobject.sourceforge.net/
COMMENT=	Allows you to translate RDBMS table rows into Python objects
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/SQLObject-0.12.2
USE_LANGUAGES=	# none

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PLIST_SUBST+=	EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

.include "options.mk"

.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
