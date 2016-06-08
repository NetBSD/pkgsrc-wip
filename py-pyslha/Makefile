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
