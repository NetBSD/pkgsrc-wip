# $NetBSD: Makefile,v 1.2 2004/05/10 10:03:52 marc Exp $
#

DISTNAME=	python-dateutil-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	time python
MASTER_SITES=	http://www.pybsd.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	https://moin.conectiva.com.br/DateUtil
COMMENT=	Extensions to the standard datetime module

USE_BUILDLINK3=	yes
PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

PYTHON_VERSIONS_ACCEPTED=	23pth 23

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
