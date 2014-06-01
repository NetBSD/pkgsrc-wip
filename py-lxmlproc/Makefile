# $NetBSD: Makefile,v 1.5 2014/06/01 12:49:43 thomasklausner Exp $
#

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

.include "../../mk/bsd.prefs.mk"

# ftp: Unsupported URL scheme `https'
.if ${OPSYS} == "NetBSD"
.endif

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/src/lxmlproc ${WRKSRC}/src/lxmlproc${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
