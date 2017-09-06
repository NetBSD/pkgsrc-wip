# $NetBSD$

PKGNAME=		uthash-2.0.2
CATEGORIES=		devel
DISTNAME=		${PKGNAME_NOREV}
MASTER_SITES=		${MASTER_SITE_GITHUB:=troydhanson/}
GITHUB_PROJECT=		uthash
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		izaac@setec.org
HOMEPAGE=		http://troydhanson.github.io/uthash/
COMMENT=		Hash table, implemented in C
LICENSE=		2-clause-bsd # actually, 1-clause

EXTRACT_USING=		bsdtar
NO_BUILD=		yes
INSTALLATION_DIRS+=	include share/doc/uthash

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/uthash

.include "../../mk/bsd.pkg.mk"
