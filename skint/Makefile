# $NetBSD$

DISTNAME=	skint-052
PKGNAME=	skint-0.5.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=false-schemers/}
GITHUB_TAG=	v052

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/false-schemers/skint/
COMMENT=	Cheap and fast R7RS Scheme Interpreter
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/${PKGNAME_NOREV}
INSTALLATION_DIRS+=	share/doc/${PKGNAME_NOREV}
INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/[skint].c ${DESTDIR}${PREFIX}/share/${PKGNAME_NOREV}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}

.include "../../mk/bsd.pkg.mk"
