# $NetBSD: Makefile,v 1.1.1.1 2011/04/02 22:36:43 jihbed Exp $
#

DISTNAME=	bidict-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/b/bidict/

MAINTAINER=	kamek.derouiche@gmail.com
HOMEPAGE=	http://bitbucket.org/jab/bidict
COMMENT=	Bidirectional (one-to-one) mapping data structure
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/bidict-0.1.1
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
