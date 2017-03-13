# $NetBSD$

DISTNAME=	hashcat-utils-1.7
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashcat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hashcat/hashcat/
COMMENT=	Set of small utilities that are useful in advanced password cracking
LICENSE=	mit

GITHUB_TAG=	v${PKGVERSION_NOREV}

USE_TOOLS+=	perl
BUILD_DIRS=	src
BUILD_TARGET=	native
REPLACE_PERL=	src/*.pl

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/*.bin ${DESTDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/src/*.pl ${DESTDIR}${PREFIX}/bin/

#	for f in ${WRKSRC}/src/*.bin; do \
#	${INSTALL_PROGRAM} ${f} ${DESTDIR}${PREFIX}/bin/ \
#	done
#	for s in ${WRKSRC}/src/*.pl; do \
#		${INSTALL_SCRIPT} ${s} ${DESTDIR}${PREFIX}/bin/ \
#	done

.include "../../mk/bsd.pkg.mk"
