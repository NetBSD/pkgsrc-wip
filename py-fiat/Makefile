# $NetBSD: Makefile,v 1.3 2012/10/07 11:54:33 asau Exp $
#

DISTNAME=	fiat-1.0.0
CATEGORIES=	math python
MASTER_SITES=	http://launchpad.net/fiat/1.0.x/1.0.0/+download/
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	https://launchpad.net/fiat
COMMENT=	FInite element Automatic Tabulator

FETCH_USING=	curl

LICENSE=	gnu-lgpl-v3

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
