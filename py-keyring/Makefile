# $NetBSD: Makefile,v 1.2 2012/10/07 12:25:13 asau Exp $
#

DISTNAME=	keyring-0.2.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	security
MASTER_SITES=	http://pypi.python.org/packages/source/k/keyring/
EXTRACT_SUFX=	.gz#md5=4a640c4d41c6aa702cf6122d1a22ece3

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://pypi.python.org/packages/source/k/keyring/
COMMENT=	Store and access your passwords safely
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/keyring-0.2
USE_LANGUAGES=	c c++

PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
