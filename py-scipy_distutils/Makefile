# $NetBSD: Makefile,v 1.5 2006/05/19 16:51:33 ykomatsu Exp $
#

DISTNAME=		SciPy-0.2.0_alpha_200.4161_src
PKGNAME=		${PYPKGPREFIX}-scipy_distutils-0.2.0
WRKSRC=			${WRKDIR}/${DISTNAME:S/_src//}
CATEGORIES=		devel
MASTER_SITES=		http://www.scipy.org/site_content/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.scipy.org/
COMMENT=		SciPy distutils: standalone package

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PYSETUPSUBDIR=		scipy_core/scipy_distutils/

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
