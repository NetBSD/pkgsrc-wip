# $NetBSD: Makefile,v 1.1.1.1 2012/08/25 16:59:53 jihbed Exp $
#

DISTNAME=	lxmlproc-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/downloads/nicferrier/lxmlproc/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/nicferrier/lxmlproc
COMMENT=	Lxml version of xsltproc
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-lxml=>2.3.2:../../textproc/py-lxml

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/src/lxmlproc ${WRKSRC}/src/lxmlproc${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
