# $NetBSD: Makefile,v 1.4 2005/04/11 21:15:22 tvierling Exp $
#

DISTNAME=		weave-0.2.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://www.scipy.org/site_content/weave/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.scipy.org/site_content/weave/
COMMENT=		Allows the inclusion of C/C++ within Python code

DEPENDS+=               ${PYPKGPREFIX}-scipy_distutils-[0-9]*:../../wip/py-scipy_distutils

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

CONFLICTS=		${PYPKGPREFIX}-SciPy-[0-9]*

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
