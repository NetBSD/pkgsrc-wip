# $NetBSD: Makefile,v 1.6 2005/04/11 21:13:50 tvierling Exp $
#

DISTNAME=		libpusb
PKGNAME=		libpusb-0.1
CATEGORIES=		devel
MASTER_SITES=		http://benoit.is-a-geek.net/bsd-tmp/

MAINTAINER=		imil@gcu.info
COMMENT=		Simple and portable USB development interface

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ONLY_FOR_PLATFORM=      FreeBSD-*-* NetBSD-*-* OpenBSD-*-* Linux-*-*

WRKSRC=			${WRKDIR}/libpusb/src

INSTALL_TARGET=		install includes

pre-build:
			@cd ${WRKSRC} && ${MAKE} clean # archive's dirty

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	"Setting up hardcoded path."
SUBST_FILES.path=	Makefile
SUBST_STAGE.path=	post-patch
SUBST_SED.path=		-e 's|/usr/pkg|${LOCALBASE}|'

.include "../../mk/bsd.pkg.mk"
