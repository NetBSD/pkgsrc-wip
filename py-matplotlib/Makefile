# $NetBSD: Makefile,v 1.1.1.1 2003/11/22 13:24:08 mpasternak Exp $
#

DISTNAME=		matplotlib-0.32
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=matplotlib/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://matplotlib.sourceforge.net/
COMMENT=		Matlab-style plotting package for Python

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

USE_BUILDLINK2=		yes

DEPENDS+=		${PYPKGPREFIX}-Numeric>=23.1:../../wip/py-Numeric

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
