# $NetBSD$

DISTNAME=	Crypt-MatrixSSL3-v${PKGVERSION_NOREV}
PKGNAME=	matrixssl-3.9.3
CATEGORIES=	security
MASTER_SITES=	https://cpan.metacpan.org/authors/id/P/PO/POWERMAN/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/powerman/perl-Crypt-MatrixSSL3
COMMENT=	Small embedded SSL implementation
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}/inc/${PKGNAME_NOREV:S/./-/g}-open

USE_TOOLS+=	gmake

MAKE_ENV+=	MATRIXSSL_ROOT=${WRKSRC:Q}

INSTALLATION_DIRS=	include/matrixssl/core include/matrixssl/crypto lib/matrixssl

post-extract:
	cd ${WRKDIR}/${DISTNAME}/inc; \
		${TAR} -zxf matrixssl-3-9-3-open.tar.gz

do-install:
	cd ${WRKSRC}; \
	for f in matrixssl/*.h; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/include/matrixssl; \
	done; \
	for f in core/*.h; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/include/matrixssl/core; \
	done; \
	for f in crypto/*.h; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/include/matrixssl/crypto; \
	done; \
	for f in crypto/libcrypt_s.a core/libcore_s.a matrixssl/libssl_s.a; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/lib/matrixssl; \
	done

.include "../../mk/bsd.pkg.mk"
