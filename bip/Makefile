# $NetBSD$

DISTNAME=		bip-0.8.9
CATEGORIES=		chat
MASTER_SITES=		https://projects.duckcorp.org/attachments/download/61/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://bip.milkypond.org/
COMMENT=		IRC proxy
LICENSE=		gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=		c

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/bip
MAKE_ENV+=		PKGSRC_BIP_EGDIR=${EGDIR}
INSTALLATION_DIRS+=	${EGDIR}

.include "../../mk/bsd.pkg.mk"
