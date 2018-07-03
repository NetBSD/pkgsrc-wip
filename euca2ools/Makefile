# $NetBSD: Makefile,v 1.9 2015/04/06 09:13:02 thomasklausner Exp $

GIT_PKG=		euca2ools
GIT_LEVEL=		2.1.3

DISTNAME=		${GIT_LEVEL}
PKGNAME=		${GIT_PKG}-${GIT_LEVEL}
CATEGORIES=		sysutils
MASTER_SITES=		https://github.com/eucalyptus/${GIT_PKG}/archive/
EXTRACT_SUFX=		.zip

MAINTAINER=		noud4@users.sourceforge.net
HOMEPAGE=		http://www.eucalyptus.com/download/${GIT_PKG}
COMMENT=		Amazon Web Services (AWS) interactor
LICENSE=		2-clause-bsd

DEPENDS+=		${PYPKGPREFIX}-boto>=2.2:../../net/py-boto
DEPENDS+=		${PYPKGPREFIX}-m2crypto>=0.20.2:../../security/py-m2crypto

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-m2crypto

DIST_SUBDIR=		${GIT_PKG}
USE_LANGUAGES=		# python
USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/${GIT_PKG}-${GIT_LEVEL}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
EGG_NAME=${GIT_PKG}-0.0.0
.include "../../mk/bsd.pkg.mk"
