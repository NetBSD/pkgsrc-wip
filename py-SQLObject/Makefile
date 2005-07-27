# $NetBSD: Makefile,v 1.4 2005/07/27 16:27:48 thomasklausner Exp $
#

DISTNAME=		SQLObject-0.5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sqlobject/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://sqlobject.sourceforge.net/
COMMENT=		Allows you to translate RDBMS table rows into Python objects

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
