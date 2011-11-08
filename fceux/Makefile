# $NetBSD: Makefile,v 1.1.1.1 2011/11/08 15:48:08 othyro Exp $
#

DISTNAME=	fceux-2.1.5.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	emulators
MASTER_SITES=	http://sourceforge.net/projects/fceultra/files/Source%20Code/2.1.5%20src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fceux.com/
COMMENT=	NES, Famicom, and Famicom Disk System (FDS) emulator
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/fceu2.1.5
#USE_CMAKE=		yes
USE_LANGUAGES=		c c++
BUILD_DEPENDS+=		scons-[0-9]*:../../devel/scons
USE_TOOLS+=		pkg-config
INSTALLATION_DIRS+=	bin

.include "options.mk"

do-build:
		cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons

do-install:
		cd ${WRKSRC} && \
		${INSTALL_PROGRAM} src/fceux ${DESTDIR}${PREFIX}/bin/fceux

.include "../../mk/bsd.pkg.mk"
