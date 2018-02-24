# $NetBSD: Makefile,v 1.230 2017/01/26 16:31:57 jperkin Exp $

DISTNAME=	openssl-1.1.0g
CATEGORIES=	security
MASTER_SITES=	https://www.openssl.org/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openssl.org/
COMMENT=	Secure Socket Layer and cryptographic library
LICENSE=	openssl

USE_TOOLS=		perl
#CONF_FILES=		${PKG_SYSCONFDIR}/ssl/openssl.cnf
OWN_DIRS=		${PKG_SYSCONFDIR}/ssl/certs ${PKG_SYSCONFDIR}/ssl/private

PKGCONFIG_OVERRIDE+=		libcrypto.pc libssl.pc openssl.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

CONFIGURE_ENV+=		PERL=${PERL5}
CONFIGURE_ARGS+=	--openssldir=${PKG_SYSCONFDIR}/ssl
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	-Wl,-rpath,${PREFIX}/lib

do-configure:
	cd ${WRKSRC}; env ${CONFIGURE_ENV} ./config ${CONFIGURE_ARGS}

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
