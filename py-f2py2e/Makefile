# $NetBSD: Makefile,v 1.5 2005/07/27 16:27:55 thomasklausner Exp $
#

DISTNAME=		F2PY-2-latest
PKGNAME=		${PYPKGPREFIX}-f2py2e-2.37.233
WRKSRC=			${WRKDIR}/F2PY-2.37.233-1545
CATEGORIES=		devel
MASTER_SITES=		http://cens.ioc.ee/projects/f2py2e/2.x/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://cens.ioc.ee/projects/f2py2e/
COMMENT=		Fortran to Python interface generator

DEPENDS+=		${PYPKGPREFIX}-scipy_distutils-[0-9]*:../../wip/py-scipy_distutils

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
