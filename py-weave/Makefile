# $NetBSD: Makefile,v 1.2 2003/11/23 13:18:12 mpasternak Exp $
#

DISTNAME=		weave-0.2.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://www.scipy.org/site_content/weave/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.scipy.org/site_content/weave/
COMMENT=		Allows the inclusion of C/C++ within Python code

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

CONFLICTS=		${PYPKGPREFIX}-SciPy-[0-9]*

.include "../../wip/py-scipy_distutils/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
