# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 21:59:40 jihbed Exp $
#

DISTNAME=	mcint-0.1dev5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	physics python
MASTER_SITES=	http://pypi.python.org/packages/source/m/mcint/
EXTRACT_SUFX=	.zip#md5=2f8d65a42f38e3640b61f074e280982a

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/mcint/
COMMENT=	Simple tool to perform numerical integration using MC techniques

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
