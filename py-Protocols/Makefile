# $NetBSD: Makefile,v 1.1.1.1 2004/02/26 20:37:43 mpasternak Exp $
#

DISTNAME=		PyProtocols-0.9.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/Py//}
WRKSRC=			${WRKDIR}/pyprotocols-0.9.2/
CATEGORIES=		devel
MASTER_SITES=		http://peak.telecommunity.com/dist/
EXTRACT_SUFX=		.zip

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://peak.telecommunity.com/PyProtocols.html
COMMENT=		Lets you easily define your own protocols and adapters

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
