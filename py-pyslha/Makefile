# $NetBSD: Makefile,v 1.1.1.1 2011/03/07 11:47:21 jihbed Exp $
#

DISTNAME=	pyslha-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyslha/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/packages/source/p/pyslha/
COMMENT=	Parsing, manipulating, and visualising SUSY Les Houches Accord data
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/isawig2slha ${WRKSRC}/isawig2slha${PYVERSSUFFIX}
	${MV} ${WRKSRC}/slha2isawig ${WRKSRC}/slha2isawig${PYVERSSUFFIX}
	${MV} ${WRKSRC}/slhaplot ${WRKSRC}/slhaplot${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
