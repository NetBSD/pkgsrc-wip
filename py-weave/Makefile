# $NetBSD: Makefile,v 1.1.1.1 2003/11/22 18:58:55 mpasternak Exp $
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

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
