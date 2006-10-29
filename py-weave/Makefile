# $NetBSD: Makefile,v 1.8 2006/10/29 08:32:54 shattered Exp $
#

DISTNAME=		weave-0.2.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://www.scipy.org/site_content/weave/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.scipy.org/Weave
COMMENT=		Allows the inclusion of C/C++ within Python code

DEPENDS+=		${PYPKGPREFIX}-scipy_distutils-[0-9]*:../../wip/py-scipy_distutils

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

CONFLICTS=		${PYPKGPREFIX}-SciPy-[0-9]*

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
