# $NetBSD: Makefile,v 1.3 2005/04/11 21:14:55 tvierling Exp $
#

DISTNAME=		PEAK-0.5a3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://peak.telecommunity.com/dist/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://peak.telecommunity.com/
COMMENT=		Python Enterprise Application Kit

CONFLICTS+=		${PYPKGPREFIX}-ZODB-*

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../wip/py-Protocols/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
