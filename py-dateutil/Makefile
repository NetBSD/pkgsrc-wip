# $NetBSD: Makefile,v 1.4 2005/04/11 21:14:58 tvierling Exp $
#

DISTNAME=	python-dateutil-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	time python
MASTER_SITES=	http://www.pybsd.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	https://moin.conectiva.com.br/DateUtil
COMMENT=	Extensions to the standard datetime module

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

PYTHON_VERSIONS_ACCEPTED=	23

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
