# $NetBSD: Makefile,v 1.9 2003/11/23 00:19:42 mpasternak Exp $
#

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth

.include "../../wip/py-twisted/Makefile.common"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
