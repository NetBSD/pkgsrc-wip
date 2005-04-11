# $NetBSD: Makefile,v 1.3 2005/04/11 21:14:57 tvierling Exp $
#

DISTNAME=		SQLObject-0.5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sqlobject/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://sqlobject.sourceforge.net/
COMMENT=		Allows you to translate RDBMS table rows into Python objects

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
