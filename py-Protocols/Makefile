# $NetBSD: Makefile,v 1.6 2005/07/27 16:27:29 thomasklausner Exp $
#

DISTNAME=		PyProtocols-0.9.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=		devel
MASTER_SITES=		http://peak.telecommunity.com/dist/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://peak.telecommunity.com/PyProtocols.html
COMMENT=		Lets you easily define your own protocols and adapters

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PYBINMODULE=		# defined

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
