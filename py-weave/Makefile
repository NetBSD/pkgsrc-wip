# $NetBSD: Makefile,v 1.3 2004/05/10 00:07:33 blef Exp $
#

DISTNAME=		weave-0.2.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://www.scipy.org/site_content/weave/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.scipy.org/site_content/weave/
COMMENT=		Allows the inclusion of C/C++ within Python code

DEPENDS+=               ${PYPKGPREFIX}-scipy_distutils-[0-9]*:../../wip/py-scipy_distutils

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

CONFLICTS=		${PYPKGPREFIX}-SciPy-[0-9]*

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
