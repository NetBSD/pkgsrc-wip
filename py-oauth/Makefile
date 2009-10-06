# $NetBSD: Makefile,v 1.1.1.1 2009/10/06 10:19:30 fhajny Exp $

PKGNAME=	${PYPKGPREFIX}-oauth-1.0.1
DISTNAME=	python
CATEGORIES=	security python
MASTER_SITES=	http://oauth.googlecode.com/svn/code/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://code.google.com/p/oauth/
COMMENT=	Python bindings for OAuth
LICENSE=	mit

.include "../../mk/bsd.prefs.mk"

SVNREVISION=	r1130

NO_CHECKSUM=	yes
PYDISTUTILSPKG=	# yes
PYTHON_VERSIONS_ACCEPTED=	26 25 24
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

BUILD_DEPENDS+=	subversion-base-[0-9]*:../../devel/subversion-base

EGDIR=		share/examples/py-oauth

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	${EGDIR}

do-fetch:
do-extract:
	cd ${WRKDIR} && svn export -r ${SVNREVISION} ${MASTER_SITES}${DISTNAME}

post-install:
	${INSTALL_DATA} ${WRKSRC}/oauth/example/*.py ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
