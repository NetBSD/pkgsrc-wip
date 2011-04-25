# $NetBSD: Makefile,v 1.3 2011/04/25 21:16:09 jihbed Exp $
#

DISTNAME=	pyslha-1.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	physics
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyslha/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.insectnation.org/projects/pyslha
COMMENT=	Parsing, manipulating, and visualising SUSY Les Houches Accord data
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pyslha-1.2.3

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/isawig2slha ${WRKSRC}/isawig2slha${PYVERSSUFFIX}
	${MV} ${WRKSRC}/slha2isawig ${WRKSRC}/slha2isawig${PYVERSSUFFIX}
	${MV} ${WRKSRC}/slhaplot ${WRKSRC}/slhaplot${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
