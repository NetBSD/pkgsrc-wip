# $NetBSD: Makefile,v 1.1.1.1 2004/01/09 13:59:48 mpasternak Exp $
#

DISTNAME=		SQLObject-0.5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sqlobject/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://sqlobject.sourceforge.net/
COMMENT=		Allows you to translate RDBMS table rows into Python objects

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
