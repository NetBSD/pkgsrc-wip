# $NetBSD: Makefile,v 1.5 2006/05/19 16:51:32 ykomatsu Exp $
#

DISTNAME=		SQLObject-0.5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sqlobject/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sqlobject.sourceforge.net/
COMMENT=		Allows you to translate RDBMS table rows into Python objects

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
