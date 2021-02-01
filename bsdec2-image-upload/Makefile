# $NetBSD: Makefile,v 1.4 2020/01/18 21:50:52 jperkin Exp $

DISTNAME=	bsdec2-image-upload-1.3.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=cperciva/}

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	https://github.com/cperciva/bsdec2-image-upload/
COMMENT=	Tool for creating Amazon EC2 AMIs
LICENSE=	2-clause-bsd

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mgcc)
CFLAGS+=	-Wno-error=pointer-sign \
		-Wno-error=maybe-uninitialized \
		-Wno-error=discarded-qualifiers \
		-Wno-error=cast-qual \
		-Wno-error=clobbered
.elif !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-unknown-warning-option -Wno-pointer-sign \
		-Wno-incompatible-pointer-types-discards-qualifiers
.endif
BUILDLINK_TRANSFORM+=	rm:-Wno-error=\#warnings

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsdec2-image-upload ${DESTDIR}${PREFIX}/bin

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
