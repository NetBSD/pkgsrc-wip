# $NetBSD: Makefile,v 1.2 2012/11/16 23:59:10 noud4 Exp $
#

DISTNAME=	Forthon-0.8.10
PKGNAME=        ${PYPKGPREFIX}-forthon-0.8.10
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	http://hifweb.lbl.gov/Forthon/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://hifweb.lbl.gov/Forthon/
COMMENT=	Fortran95 wrapper/code development package
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c fortran

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/Forthon ${WRKSRC}/Forthon${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
