# $NetBSD: Makefile,v 1.1 2021/11/06 16:40:06 rhialto Exp $

DISTNAME=	xemu-0.0.2025.04.23
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=lgblgblgb/}
GITHUB_PROJECT=	xemu
GITHUB_TAG=	84a7e25401f93aa18e449c710467e9d493e586f6

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/lgblgblgb/xemu
COMMENT=	Emulators of various machines, incl the MEGA65
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	bash gmake pkg-config
USE_TOOLS+=	grep sed tr cut dirname pwd uname date
USE_LANGUAGES+=	c

REPLACE_BASH+=	build/configure/configure

MAKE_ENV+=	DESTDIR=${DESTDIR}
MAKE_ENV+=	SDL2_RPATH=${COMPILER_RPATH_FLAG},${BUILDLINK_PREFIX.SDL2}/lib
MAKE_FLAGS+=	RELEASE=yes

INSTALLATION_DIRS+=	share/xemu-lgb

# This subst only for NetBSD?
SUBST_CLASSES+=		rl
SUBST_STAGE.rl=		pre-configure
SUBST_SED.rl=		-e 's/-lreadline/-ledit/'
SUBST_FILES.rl+=	build/configure/configure
SUBST_MESSAGE.rl=	readline

SUBST_CLASSES+=		usrlocal
SUBST_STAGE.usrlocal=	pre-configure
SUBST_SED.usrlocal=	-e 's;/usr/local;${PREFIX};'
SUBST_FILES.usrlocal+=	./xemu/emutools_files.h
SUBST_MESSAGE.usrlocal=	Replacing /usr/local

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	pre-configure
SUBST_SED.destdir=	-e 's;/usr/local;$${DESTDIR}${PREFIX};'
SUBST_FILES.destdir+=	./build/Makefile.common
SUBST_MESSAGE.destdir=	Inserting DESTDIR into INSTALL_BINDIR

do-configure:
	cd ${WRKSRC}/build/configure && ./configure --arch=native

post-install:
	${INSTALL_DATA} ${WRKSRC}/rom/clcd-u104-parasite.rom ${DESTDIR}${PREFIX}/share/xemu-lgb/
	${INSTALL_DATA} ${WRKSRC}/rom/vic20-emulator-tool.rom ${DESTDIR}${PREFIX}/share/xemu-lgb/

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
