# $NetBSD: Makefile,v 1.7 2015/01/10 20:22:03 thomasklausner Exp $

DISTNAME=	pyslha-1.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyslha/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.insectnation.org/projects/pyslha
COMMENT=	Parsing, manipulating, and visualising SUSY Les Houches Accord data
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 1.2.3

post-extract:
	${MV} ${WRKSRC}/isawig2slha ${WRKSRC}/isawig2slha${PYVERSSUFFIX}
	${MV} ${WRKSRC}/slha2isawig ${WRKSRC}/slha2isawig${PYVERSSUFFIX}
	${MV} ${WRKSRC}/slhaplot ${WRKSRC}/slhaplot${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
