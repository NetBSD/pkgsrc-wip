# $NetBSD: Makefile,v 1.5 2005/04/11 21:14:55 tvierling Exp $
#

DISTNAME=		PyProtocols-0.9.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=		devel
MASTER_SITES=		http://peak.telecommunity.com/dist/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://peak.telecommunity.com/PyProtocols.html
COMMENT=		Lets you easily define your own protocols and adapters

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PYBINMODULE=		# defined

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
