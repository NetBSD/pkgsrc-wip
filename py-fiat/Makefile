# $NetBSD: Makefile,v 1.4 2013/03/23 13:29:16 outpaddling Exp $
#

DISTNAME=	fiat-${MMVERSION}.0
CATEGORIES=	math python
MASTER_SITES=	http://launchpad.net/fiat/${MMVERSION}.x/${MMVERSION}.0/+download/
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	https://launchpad.net/fiat
COMMENT=	Finite element Automatic Tabulator

FETCH_USING=	curl

LICENSE=	gnu-lgpl-v3

PYDISTUTILSPKG=	yes

MMVERSION=	1.1

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
