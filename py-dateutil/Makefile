# $NetBSD: Makefile,v 1.1.1.1 2003/11/25 19:43:17 marc Exp $
#

DISTNAME=	python-dateutil-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	time python
MASTER_SITES=	http://www.pybsd.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	https://moin.conectiva.com.br/DateUtil
COMMENT=	Extensions to the standard datetime module

USE_BUILDLINK2=	yes
PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

PYTHON_VERSIONS_ACCEPTED=	23pth 23

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
