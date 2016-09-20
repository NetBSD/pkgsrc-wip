# $NetBSD: Makefile,v 1.2 2012/10/06 17:13:24 asau Exp $

PYDNS_VER=	2.3.6
DISTNAME=	pydns-${PYDNS_VER}
PKGNAME=	${PYPKGPREFIX}-DNS-${PYDNS_VER}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pydns/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://pydns.sourceforge.net/
COMMENT=	Python DNS library

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
