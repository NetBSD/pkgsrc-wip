# $NetBSD: Makefile,v 1.4 2005/07/27 16:29:32 thomasklausner Exp $
#

DISTNAME=		xsdb
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}-0.1
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xsdb/}
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xsdb.sourceforge.net/
COMMENT=		Concurrent database with concurrency control and recovery

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
