# $NetBSD: Makefile,v 1.11 2012/10/06 17:13:26 asau Exp $
#

DISTNAME=	pydirector-1.0.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pythondirector/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pythondirector.sourceforge.net/
COMMENT=		Pure-python TCP load balancer

DEPENDS+=		${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=		${PYPKGPREFIX}-m2crypto>=0.13:../../security/py-m2crypto

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
