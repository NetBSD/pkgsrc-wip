# $NetBSD: Makefile,v 1.3 2004/08/02 20:10:33 minskim Exp $
#

DISTNAME=		pydirector-0.0.7
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/pythondirector/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://cesnet.dl.sourceforge.net/sourceforge/pythondirector/
COMMENT=		Pure-python TCP load balancer

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

DEPENDS+=		${PYPKGPREFIX}-Twisted-[0-9]*:../../net/py-twisted

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
