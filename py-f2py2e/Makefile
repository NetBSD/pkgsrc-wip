# $NetBSD: Makefile,v 1.1.1.1 2003/11/23 12:07:27 mpasternak Exp $
#

DISTNAME=		F2PY-2-latest
PKGNAME=		${PYPKGPREFIX}-f2py2e-2.37.233
WRKSRC=			${WRKDIR}/F2PY-2.37.233-1545
CATEGORIES=		devel
MASTER_SITES=		http://cens.ioc.ee/projects/f2py2e/2.x/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://cens.ioc.ee/projects/f2py2e/
COMMENT=		Fortran to Python interface generator

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
