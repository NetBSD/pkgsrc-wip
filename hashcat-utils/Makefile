# $NetBSD$

DISTNAME=	hashcat-utils-1.8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashcat/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hashcat/hashcat/
COMMENT=	Set of small utilities that are useful in advanced password cracking
LICENSE=	mit

USE_TOOLS+=	perl
BUILD_DIRS=	src
BUILD_TARGET=	native
REPLACE_PERL=	src/*.pl

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/*.bin ${DESTDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/src/*.pl ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
