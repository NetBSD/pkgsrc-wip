# $NetBSD: Makefile,v 1.6 2009/06/10 00:17:17 jihbed Exp $
#

DISTNAME=	SQLObject-0.10.6.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/S/SQLObject/
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sqlobject.sourceforge.net/
COMMENT=	Allows you to translate RDBMS table rows into Python objects
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/SQLObject-0.10.6
USE_LANGUAGES=	# none

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "options.mk"

.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
