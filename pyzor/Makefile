# $NetBSD: Makefile,v 1.10 2015/09/02 20:28:57 fhajny Exp $

DISTNAME=	pyzor-1.0.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=SpamExperts/}

MAINTAINER=	tom@replic8.net
HOMEPAGE=	https://github.com/SpamExperts/pyzor/
COMMENT=	Collaborative, networked system to detect and block spam
LICENSE=	gnu-gpl-v2

GITHUB_TAG=	release-${PKGVERSION_NOREV:S/./-/g}

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-sphinx

USE_TOOLS+=	gmake

BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

REPLACE_PYTHON=	scripts/pyzor scripts/pyzord
MESSAGE_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

BUILD_DEFS+=	PKG_SYSCONFBASE

EGDIR=			share/examples/pyzor
CONFIG_FILES=		accounts config pyzord.access pyzord.paswd servers

.for file in ${CONFIG_FILES}
CONF_FILES+=		${EGDIR}/${file}.sample ${PKG_SYSCONFDIR}/${file}
.endfor

PKG_SYSCONFSUBDIR=	pyzor

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	pre-build
SUBST_MESSAGE.etc=	Fixing default config path
SUBST_FILES.etc=	scripts/pyzord scripts/pyzor web/application.py
SUBST_SED.etc=		-e 's,/etc,${PKG_SYSCONFBASE},'

MAKE_FLAGS+=		SPHINXBUILD=sphinx-build-${PYVERSSUFFIX}
INSTALLATION_DIRS+=	${PREFIX}/${PKGMANDIR}/man1 ${EGDIR}

post-build:
	cd ${WRKSRC}/docs && ${BUILD_MAKE_CMD} man

post-install:
.for file in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/config/${file}.sample \
		${DESTDIR}${PREFIX}/${EGDIR}
.endfor
	${INSTALL_MAN} ${WRKSRC}/docs/.build/man/pyzor.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
