# $NetBSD: Makefile,v 1.8 2013/11/13 02:28:18 othyro Exp $

DISTNAME=	fceux-2.2.2.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fceultra/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fceux.com/
COMMENT=	NES, Famicom, and Famicom Disk System (FDS) emulator
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=		c c++
BUILD_DEPENDS+=		scons-[0-9]*:../../devel/scons
USE_TOOLS+=		pkg-config
INSTALLATION_DIRS+=	bin share/applications share/pixmaps

.include "options.mk"

SUBST_CLASSES+=			pkgmandir
SUBST_FILES.pkgmandir=		SConstruct
SUBST_MESSAGE.pkgmandir=	Fixing PKGMANDIR path.
SUBST_SED.pkgmandir=		-e "s|share/man|${PKGMANDIR}|g"
SUBST_STAGE.pkgmandir=		post-patch

.if ${OPSYS} != "Linux"
BUILDLINK_TRANSFORM=	rm:-ldl
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons

do-install:
	cd ${WRKSRC} && \
		${SETENV} ${INSTALL_ENV} ${PREFIX}/bin/scons install --prefix=${DESTDIR}${PREFIX}

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
