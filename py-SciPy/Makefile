# $NetBSD: Makefile,v 1.1.1.1 2003/11/23 14:04:54 mpasternak Exp $
#

DISTNAME=		SciPy-0.2.0_alpha_200.4161_src
PKGNAME=		${PYPKGPREFIX}-SciPy-0.2.0
WRKSRC=			${WRKDIR}/${DISTNAME:S/_src//}
CATEGORIES=		math
MASTER_SITES=		http://www.scipy.org/site_content/downloads/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.scipy.org/
COMMENT=		Open source library of scientific tools for Python

USE_BUILDLINK2=		yes
USE_X11=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

CONFLICTS=		${PYPKGPREFIX}-weave-[0-9]*

.include "../../math/blas/buildlink2.mk"
.include "../../math/lapack/buildlink2.mk"
.include "../../math/fftw2/buildlink2.mk"
.include "../../wip/py-f2py2e/buildlink2.mk"
.include "../../wip/py-scipy_distutils/buildlink2.mk"
.include "../../math/py-Numeric/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
