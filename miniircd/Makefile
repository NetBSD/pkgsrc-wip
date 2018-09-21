# $NetBSD: Makefile,v 1.2 2017/04/14 19:10:23 leot Exp $

DISTNAME=	miniircd-1.2.1
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_GITHUB:=jrosdahl/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/jrosdahl/miniircd/
COMMENT=	Simple Internet Relay Chat (IRC) server written in Python
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes

BUILD_DEFS+=	VARBASE MINIIRCD_USER MINIIRCD_GROUP MINIIRCD_DIR
FILES_SUBST+=   PYTHONBIN=${PYTHONBIN}
FILES_SUBST+=	MINIIRCD_USER=${MINIIRCD_USER} MINIIRCD_GROUP=${MINIIRCD_GROUP}
FILES_SUBST+=	MINIIRCD_DIR=${MINIIRCD_DIR}

MINIIRCD_USER?=		miniircd
MINIIRCD_GROUP?=	nobody
MINIIRCD_DIR?=		${VARBASE}/miniircd

OWN_DIRS+=	${MINIIRCD_DIR}

PKG_GROUPS=	${MINIIRCD_GROUP}
PKG_USERS=	${MINIIRCD_USER}:${MINIIRCD_GROUP}

RCD_SCRIPTS=	miniircd

REPLACE_PYTHON+=	miniircd
REPLACE_PYTHON+=	test.py

USE_LANGUAGES=		# none

INSTALLATION_DIRS=	sbin share/doc/miniircd

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/miniircd ${DESTDIR}${PREFIX}/sbin/miniircd
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/miniircd/README

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
