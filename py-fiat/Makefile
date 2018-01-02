# $NetBSD: Makefile,v 1.6 2014/06/01 12:49:41 thomasklausner Exp $
#

DISTNAME=	fiat-${MMVERSION}
CATEGORIES=	math python
MASTER_SITES=	http://launchpad.net/fiat/${MMVERSION}.x/release-${MMVERSION}/+download/
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://launchpad.net/fiat
COMMENT=	Finite element Automatic Tabulator


LICENSE=	gnu-lgpl-v3

PYDISTUTILSPKG=	yes

MMVERSION=	1.1

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
