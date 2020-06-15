# $NetBSD$

DISTNAME=	pyPEG2-2.15.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	textproc python
MASTER_SITES=	http://fdik.org/pyPEG2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fdik.org/pyPEG2/
COMMENT=	Intrinsic PEG Parser-Interpreter for Python
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
