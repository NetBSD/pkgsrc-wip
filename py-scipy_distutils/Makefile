# $NetBSD: Makefile,v 1.2 2004/05/09 23:50:57 blef Exp $
#

DISTNAME=		SciPy-0.2.0_alpha_200.4161_src
PKGNAME=		${PYPKGPREFIX}-scipy_distutils-0.2.0
WRKSRC=			${WRKDIR}/${DISTNAME:S/_src//}
CATEGORIES=		devel
MASTER_SITES=		http://www.scipy.org/site_content/downloads/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.scipy.org/
COMMENT=		SciPy distutils: standalone package

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PYSETUPSUBDIR=		scipy_core/scipy_distutils/

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
