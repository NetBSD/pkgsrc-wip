# $NetBSD: Makefile,v 1.1.1.1 2004/01/15 13:23:24 mpasternak Exp $
#

DISTNAME=		xsdb
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}-0.1
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xsdb/}
EXTRACT_SUFX=		.zip

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://xsdb.sourceforge.net/
COMMENT=		Concurrent database with concurrency control and recovery

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
