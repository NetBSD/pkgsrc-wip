# $NetBSD: Makefile,v 1.3 2004/02/26 22:49:55 mpasternak Exp $
#

DISTNAME=		PyProtocols-0.9.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=		devel
MASTER_SITES=		http://peak.telecommunity.com/dist/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://peak.telecommunity.com/PyProtocols.html
COMMENT=		Lets you easily define your own protocols and adapters

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
