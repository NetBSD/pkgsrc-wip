# $NetBSD: Makefile,v 1.1.1.1 2003/11/08 11:48:57 mpasternak Exp $
#

DISTNAME=		pydirector-0.0.7
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/pythondirector/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://cesnet.dl.sourceforge.net/sourceforge/pythondirector/
COMMENT=		Pure-python TCP load balancer

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

DEPENDS+=		${PYPKGPREFIX}-Twisted-[0-9]*:../../wip/py-twisted

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
