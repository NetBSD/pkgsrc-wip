# $NetBSD: Makefile,v 1.4 2005/06/12 23:51:26 kristerw Exp $
#

DISTNAME=		SciPy-0.2.0_alpha_200.4161_src
PKGNAME=		${PYPKGPREFIX}-SciPy-0.2.0
CATEGORIES=		math
MASTER_SITES=		http://www.scipy.org/site_content/downloads/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.scipy.org/
COMMENT=		Open source library of scientific tools for Python

DEPENDS+=		${PYPKGPREFIX}-scipy_distutils-[0-9]*:../../wip/py-scipy_distutils

WRKSRC=			${WRKDIR}/${DISTNAME:S/_src//}
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

CONFLICTS=		${PYPKGPREFIX}-weave-[0-9]*

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/fftw2/buildlink3.mk"
.include "../../wip/py-f2py2e/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
