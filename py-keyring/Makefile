# $NetBSD: Makefile,v 1.1.1.1 2010/05/12 16:10:47 jihbed Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/keyring-0.2
USE_LANGUAGES=	c c++

PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
