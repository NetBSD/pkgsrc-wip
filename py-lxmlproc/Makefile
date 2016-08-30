# $NetBSD: Makefile,v 1.6 2015/01/10 20:20:37 thomasklausner Exp $

DISTNAME=	lxmlproc-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/downloads/nicferrier/lxmlproc/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/nicferrier/lxmlproc
COMMENT=	Lxml version of xsltproc
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-lxml>=2.3.2:../../textproc/py-lxml

USE_LANGUAGES=	# none

post-extract:
	${MV} ${WRKSRC}/src/lxmlproc ${WRKSRC}/src/lxmlproc${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
