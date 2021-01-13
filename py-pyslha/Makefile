# $NetBSD$

DISTNAME=	pyslha-3.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyslha/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.insectnation.org/projects/pyslha
COMMENT=	Parsing, manipulating and visualising SUSY Les Houches Accord data
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-tex2pix>=0.1.5:../../wip/py-tex2pix

post-extract:
	${MV} ${WRKSRC}/slhaplot ${WRKSRC}/slhaplot${PYVERSSUFFIX}
	${MV} ${WRKSRC}/slha2isawig ${WRKSRC}/slha2isawig${PYVERSSUFFIX}
	${MV} ${WRKSRC}/isawig2slha ${WRKSRC}/isawig2slha${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
