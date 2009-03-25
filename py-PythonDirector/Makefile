# $NetBSD: Makefile,v 1.9 2009/03/25 14:16:43 jihbed Exp $
#

DISTNAME=	pydirector-1.0.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pythondirector/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pythondirector.sourceforge.net/
COMMENT=		Pure-python TCP load balancer

DEPENDS+=		${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=		py25-m2crypto>=0.13:../../security/py-m2crypto

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
