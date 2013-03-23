# $NetBSD: Makefile,v 1.6 2013/03/23 13:22:33 outpaddling Exp $
#

DISTNAME=	ffc-${MMVERSION}.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://launchpad.net/ffc/${MMVERSION}.x/${MMVERSION}.0/+download/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	https://launchpad.net/ffc
COMMENT=	C++ code generator for multilinear forms

LICENSE=	gnu-lgpl-v3

FETCH_USING=	curl

PYDISTUTILSPKG=	yes

MMVERSION=	1.1

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
