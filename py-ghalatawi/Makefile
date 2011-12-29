# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 22:14:10 jihbed Exp $
#

DISTNAME=	ghalatawi-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python arabic
MASTER_SITES=	http://pypi.python.org/packages/source/g/ghalatawi/
EXTRACT_SUFX=	.zip#md5=7afa6950e1786db9729f2582c451a2a9

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://ghalatawi.sourceforge.net/
COMMENT=	Ghalatawi: Arabic AUtocorrec
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
