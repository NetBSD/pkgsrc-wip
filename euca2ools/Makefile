# $NetBSD: Makefile,v 1.2 2013/02/04 08:33:33 thomasklausner Exp $
#

GIT_PKG=		euca2ools
GIT_LEVEL=		master

DISTNAME=		${GIT_LEVEL}
PKGNAME=		${GIT_PKG}-2.1.2.x
THIS_EGG_FILE=		${GIT_PKG}-0.0.0-py${PYVERSSUFFIX}.egg-info # XXX ${PKGNAME}-p
CATEGORIES=		sysutils
MASTER_SITES=		https://github.com/eucalyptus/${GIT_PKG}/archive/
EXTRACT_SUFX=		.zip

MAINTAINER=		noud4@home.nl
HOMEPAGE=		http://www.eucalyptus.com/download/${GIT_PKG}
COMMENT=		Amazon Web Services (AWS) interactor
LICENSE=		2-clause-bsd

DEPENDS+=		${PYPKGPREFIX}-boto>=2.2:../../net/py-boto
DEPENDS+=		${PYPKGPREFIX}-m2crypto>=0.20.2:../../security/py-m2crypto

FETCH_USING=		curl
DIST_SUBDIR=		${GIT_PKG}
USE_LANGUAGES=		# python
USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/${GIT_PKG}-${GIT_LEVEL}

PLIST_SUBST+=		THIS_EGG_FILE=${THIS_EGG_FILE} # XXX

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
