# $NetBSD: Makefile,v 1.7 2012/10/06 17:13:26 asau Exp $
#

DISTNAME=		PEAK-0.5a3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://peak.telecommunity.com/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://peak.telecommunity.com/
COMMENT=		Python Enterprise Application Kit

CONFLICTS+=		${PYPKGPREFIX}-ZODB-*

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../wip/py-Protocols/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
