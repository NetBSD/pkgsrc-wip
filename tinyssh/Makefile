# $NetBSD$

DISTNAME=		${GITHUB_PROJECT}
PKGNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=janmojzis/}
GITHUB_PROJECT=		tinyssh
GITHUB_TAG=		20240101

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://tinyssh.org
COMMENT=		Minimalistic SSHv2 server
LICENSE=		cc0-1.0-universal

DJB_MAKE_TARGETS=	no
BUILD_TARGET=		compile

do-install:
	cd ${WRKSRC} && ${SH} -e make-install.sh ${DESTDIR}

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
