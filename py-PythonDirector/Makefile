# $NetBSD: Makefile,v 1.6 2005/07/27 16:27:47 thomasklausner Exp $
#

DISTNAME=		pydirector-0.0.7
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/pythondirector/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://cesnet.dl.sourceforge.net/sourceforge/pythondirector/
COMMENT=		Pure-python TCP load balancer

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

DEPENDS+=		${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
