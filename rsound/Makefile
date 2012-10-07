# $NetBSD: Makefile,v 1.3 2012/10/07 14:53:44 asau Exp $
#

DISTNAME=	rsound-1.1
CATEGORIES=	audio
MASTER_SITES=	http://cloud.github.com/downloads/Themaister/RSound/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/downloads/Themaister/RSound/
COMMENT=	Multi-platform, simple PCM audio server and client
LICENSE=	gnu-gpl-v3

HAS_CONFIGURE=			yes
USE_LANGUAGES+=			c
USE_TOOLS+=			gmake
CONFIGURE_ARGS+=		--prefix=${PREFIX}
INSTALLATION_DIRS+=		bin include lib/pkgconfig ${PKGMANDIR}/man1

SUBST_CLASSES+=			pkgmandir
SUBST_STAGE.pkgmandir=		pre-install
SUBST_MESSAGE.pkgmandir=	Fixing PKGMANDIR path.
SUBST_FILES.pkgmandir=		src/Makefile
SUBST_SED.pkgmandir=		-e "s|share/man|${PKGMANDIR}|g"

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
