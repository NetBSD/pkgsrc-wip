# $NetBSD: Makefile,v 1.4 2005/07/27 16:27:27 thomasklausner Exp $
#

DISTNAME=		PEAK-0.5a3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://peak.telecommunity.com/dist/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://peak.telecommunity.com/
COMMENT=		Python Enterprise Application Kit

CONFLICTS+=		${PYPKGPREFIX}-ZODB-*

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../wip/py-Protocols/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
