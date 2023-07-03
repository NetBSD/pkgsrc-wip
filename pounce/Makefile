# $NetBSD$

DISTNAME=	pounce-3.1
CATEGORIES=	chat
MASTER_SITES=	https://git.causal.agency/pounce/snapshot/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.causal.agency/pounce/about/
COMMENT=	TLS-only multi-client IRC bouncer
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

HAS_CONFIGURE=	yes

MAKE_FLAGS=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "options.mk"

SUBST_CLASSES+=		ssl
SUBST_STAGE.ssl=	pre-configure
SUBST_MESSAGE.ssl=	Correcting the hardcoded path to OpenSSL.
SUBST_FILES.ssl+=	configure
SUBST_SED.ssl+=		-e "s,OPENSSL_BIN /usr/bin/openssl,OPENSSL_BIN ${SSLBASE}/bin/openssl,g"
SUBST_SED.ssl+=		-e "s,OPENSSL_BIN /bin/openssl,OPENSSL_BIN ${SSLBASE}/bin/openssl,g"

.include "../../security/libretls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
