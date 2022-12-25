# $NetBSD$

DISTNAME=	fidocrypt-0.0
CATEGORIES=	games
GIT_REPO=	https://github.com/riastradh/fidocrypt.git

MAINTAINER=	riastradh@NetBSD.org
HOMEPAGE=	https://github.com/riastradh/fidocrypt
COMMENT=	U2F/FIDO-based key derivation and encapsulation
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

MAKEFLAGS+=	prefix=${PREFIX}
MAKEFLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

CPPFLAGS+=	-DHAVE_FIDO_ASSERT_SET_HMAC_SECRET
CPPFLAGS+=	-DHAVE_FIDO_CRED_AUTHDATA_RAW_PTR
CPPFLAGS+=	-DHAVE_FIDO_DEV_SET_SIGMASK
CPPFLAGS+=	-DHAVE_FIDO_ED25519
CPPFLAGS+=	-DHAVE_FIDO_ES256_PK_FROM_EC_KEY_FIX
CPPFLAGS+=	-DHAVE_FIDO_RSA

.include "../../security/libfido2/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
