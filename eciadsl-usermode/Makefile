# $NetBSD: Makefile,v 1.1.1.1 2004/11/24 17:23:46 imilh Exp $
#

DISTNAME=		eciadsl-usermode-0.10
CATEGORIES=		net
MASTER_SITES=		http://benoit.is-a-geek.net/bsd-tmp/

MAINTAINER=		imil@gcu.info
COMMENT=		Driver for Globespan chipset-based ADSL USB modems

BUILD_DEPENDS+=		gettext>=0.10.35nb1:../../devel/gettext

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ONLY_FOR_PLATFORM=      FreeBSD-*-* NetBSD-*-* OpenBSD-*-* Linux-*-*

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
ALL_TARGET=		# defined

pre-build:
			cd ${WRKSRC} && ${GMAKE} clean # archive's dirty

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	"Setting up hardcoded path."
SUBST_FILES.path=	Makefile Makefile.dep 				\
			check-hdlc-bug.c check-hdlc.c eci-load1.c	\
			eci-load2.c pppoeci.c semaphore.c
SUBST_STAGE.path=	post-patch
SUBST_SED.path=		-e 's|/usr/pkg|${LOCALBASE}|'

SUBST_CLASSES+=		confpath
SUBST_FILES.confpath=	Makefile
SUBST_STAGE.confpath=	post-patch
SUBST_SED.confpath=	-e 's|^ETC_PREFIX.*|ETC_PREFIX=${LOCALBASE}/|'\
			-e 's|^CONF_PREFIX.*|CONF_PREFIX=${LOCALBASE}/|'\
			-e 's|^DOC_PREFIX.*|DOC_PREFIX=${LOCALBASE}/share/|'

.include "../../wip/libpusb/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
