# $NetBSD$

DISTNAME=	biolibc-0.2.6.10
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	9032f7b44eceb8e6e5dd75d8b0ae705e2b5f1111

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/biolibc
COMMENT=	Low-level high-performance bioinformatics library
LICENSE=	2-clause-bsd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Darwin
BUILD_TARGET=	apple
INSTALL_TARGET=	apple-install
.else
INSTALL_TARGET=	install-strip
.endif

MAKE_ENV+=	DYLIB_PATH=${PREFIX}/lib MANDIR=${PREFIX}/${PKGMANDIR}

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../wip/libxtend/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
