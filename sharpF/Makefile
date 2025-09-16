# $NetBSD$

DISTNAME=	sharpF-b302
PKGNAME=	${GITHUB_PROJECT}-0.302
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=false-schemers/}
GITHUB_PROJECT=	sharpF
GITHUB_TAG=	b302

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/false-schemers/sharpF/
COMMENT=	Compiler/runtime for a minimalistic subset of Scheme
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	bin

do-build:
	cd ${WRKSRC}/fixpoint && ${CC} -o sfc -Wall -O3 -DNDEBUG 0.c 1.c 2.c 3.c 4.c 5.c 6.c 7.c c.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fixpoint/sfc ${DESTDIR}${PREFIX}/bin/sfc

.include "../../mk/bsd.pkg.mk"
