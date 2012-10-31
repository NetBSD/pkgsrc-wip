# $NetBSD: Makefile,v 1.4 2012/10/31 12:51:55 othyro Exp $
#

DISTNAME=	fceux-2.1.5.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fceultra/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fceux.com/
COMMENT=	NES, Famicom, and Famicom Disk System (FDS) emulator
LICENSE=	gnu-gpl-v2

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

.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
