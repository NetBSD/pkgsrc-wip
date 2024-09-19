# $NetBSD: Makefile,v 1.3 2020/01/14 13:13:14 wiz Exp $

DISTNAME=	halfempty-0.40
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=googleprojectzero/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleprojectzero/halfempty/
COMMENT=	Fast, parallel test case minimization tool
LICENSE=	apache-2.0

USE_TOOLS+=	gmake pkg-config
# Tests do not work on NetBSD, see bottom of
# https://github.com/googleprojectzero/halfempty/pull/11
TEST_TARGET=	test

INSTALLATION_DIRS=	bin share/doc/halfempty

TEST_DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/halfempty ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/halfempty

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
# for putting shuf from coreutils in path
PATH:=${PATH}:${PREFIX}/gnu/bin
