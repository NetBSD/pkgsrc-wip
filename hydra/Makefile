# $NetBSD: Makefile,v 1.10 2005/01/05 20:29:20 adrian_p Exp $
#

DISTNAME=	hydra-4.5-src
PKGNAME=	hydra-4.5
WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://www.thc.org/releases/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.thc.org/
COMMENT=	Login password cracker

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
BUILD_TARGET=	all ssl

SUBST_CLASSES=		build
SUBST_STAGE.build=	post-patch
SUBST_FILES.build=	Makefile.am configure
SUBST_SED.build=	-e "s|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g" \
			-e "s|@PREFIX@|${PREFIX}|g" \
			-e "s|uname|${UNAME}|g"
SUBST_MESSAGE.build=	"Patching build files."

USE_OLD_DES_API=	YES

CONFIGURE_ARGS+=	--prefix=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hydra ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pw-inspector ${PREFIX}/bin

.include "../../security/openssl/buildlink3.mk"
.include "../../wip/libssh/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
