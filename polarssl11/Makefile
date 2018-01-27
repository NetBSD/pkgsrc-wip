# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:38 thomasklausner Exp $

DISTNAME=	polarssl-1.1.4
DISTFILES=	polarssl-1.1.4-gpl.tgz
CATEGORIES=	security
MASTER_SITES=	http://polarssl.org/code/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wongk@apt.homeunix.net
HOMEPAGE=	https://polarssl.org/download/
COMMENT=	Open Source embedded SSL/TLS cryptographic library
LICENSE=	gnu-gpl-v2

USE_TOOLS=		gmake tar

LDFLAGS.SunOS+=	-lsocket -lnsl

BINFILES=	ssl/ssl_client1 ssl/ssl_client2 ssl/ssl_server aes/aescrypt2 \
		pkey/dh_client pkey/dh_genprime pkey/dh_server pkey/mpi_demo \
		pkey/rsa_genkey pkey/rsa_sign pkey/rsa_verify hash/hello \
		hash/md5sum hash/sha1sum hash/sha2sum test/ssl_cert_test \
		test/benchmark test/selftest test/ssl_test 

INCLUDE_FILES=	aes.h arc4.h asn1.h base64.h bignum.h \
		bn_mul.h camellia.h certs.h cipher.h cipher_wrap.h config.h \
		ctr_drbg.h debug.h des.h dhm.h entropy.h entropy_poll.h \
		error.h havege.h md.h md2.h md4.h md5.h md_wrap.h net.h \
		openssl.h padlock.h pem.h pkcs11.h rsa.h sha1.h \
		sha2.h sha4.h ssl.h timing.h version.h x509.h \
		xtea.h
DSTDIR=		${WRKSRC}/.destdir
DSTDIR=		${PREFIX}

DSTDIR=		${WRKDIR}/.destdir/${PREFIX}

#install: do-install
# cmake install is broken, so we do it by hand
do-install:
	install -d ${DSTDIR}/include/polarssl
	install -d ${DSTDIR}/lib
	install -d ${DSTDIR}/bin
.for i in ${INCLUDE_FILES}
	${INSTALL_DATA} ${WRKSRC}/include/polarssl/${i} ${DSTDIR}/include/polarssl/
.endfor
	${INSTALL_DATA} ${WRKSRC}/library/libpolarssl.a ${DSTDIR}/lib/
.for i in ${BINFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/programs/${i} ${DSTDIR}/bin/polarssl_`basename ${i}`
.endfor

.include "../../mk/bsd.pkg.mk"
