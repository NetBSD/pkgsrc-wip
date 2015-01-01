# $NetBSD: Makefile,v 1.17 2015/01/01 17:35:49 jihbed Exp $

DISTNAME=	spyder-2.3.2
CATEGORIES=	devel python
MASTER_SITES=	https://bitbucket.org/spyder-ide/spyderlib/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://bitbucket.org/spyder-ide/spyderlib/
COMMENT=	Scientific PYthon Development EnviRonment
LICENSE=	mit

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c

PYDISTUTILSPKG= yes

INSTALLATION_DIRS= share/applications

post-extract:
	${CP} ${FILESDIR}/spyder.desktop ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/spyder.desktop \
		${DESTDIR}${PREFIX}/share/applications

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
DEPENDS+= 	${PYPKGPREFIX}-sphinx>=1.2.1:../../textproc/py-sphinx
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
