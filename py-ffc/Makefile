# $NetBSD: Makefile,v 1.2 2012/05/11 22:28:33 outpaddling Exp $
#

DISTNAME=	ffc-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://launchpad.net/ffc/1.0.x/1.0.0/+download/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	https://launchpad.net/ffc
COMMENT=	C++ code generator for multilinear forms

LICENSE=	gnu-lgpl-v3

FETCH_USING=	curl

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
