# $NetBSD: Makefile,v 1.2 2004/05/02 21:54:01 blef Exp $
#

DISTNAME=		SQLObject-0.5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sqlobject/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://sqlobject.sourceforge.net/
COMMENT=		Allows you to translate RDBMS table rows into Python objects

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
