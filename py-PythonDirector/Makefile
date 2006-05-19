# $NetBSD: Makefile,v 1.8 2006/05/19 16:51:32 ykomatsu Exp $
#

DISTNAME=		pydirector-0.0.7
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pythondirector/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pythondirector.sourceforge.net/
COMMENT=		Pure-python TCP load balancer

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

DEPENDS+=		${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
