# $NetBSD: Makefile,v 1.2 2012/05/11 22:29:07 outpaddling Exp $
#

DISTNAME=	fiat-1.0.0
CATEGORIES=	math python
MASTER_SITES=	http://launchpad.net/fiat/1.0.x/1.0.0/+download/
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	https://launchpad.net/fiat
COMMENT=	FInite element Automatic Tabulator

FETCH_USING=	curl

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=	gnu-lgpl-v3

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
