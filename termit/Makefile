# $NetBSD: Makefile,v 1.7 2011/10/28 12:28:51 crocusino Exp $
#

DISTNAME=	termit-2.9.1
CATEGORIES=	x11
MASTER_SITES=	https://github.com/downloads/nonstop/termit/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://wiki.github.com/nonstop/termit
COMMENT=	Simple vte-based terminal with tabs and encoding switching
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
USE_CMAKE=	yes

# fetch from https - fails with ftp
FETCH_USING=	curl

## vars to handle config files
EGDIR=				${PREFIX}/share/examples/termit
PKG_SYSCONFSUBDIR=		xdg/termit

## fix the MANPATH
## cannot use patch as ${PKGMANDIR} is not expanded in CMakeLists.txt
SUBST_CLASSES+=			fix-man-path
SUBST_STAGE.fix-man-path=	pre-configure
SUBST_MESSAGE.fix-man-path=	Fixing absolute man path.
SUBST_FILES.fix-man-path=	doc/CMakeLists.txt
SUBST_SED.fix-man-path=		-e 's,/share/man,/${PKGMANDIR},g'

## store the example configuration separately
SUBST_CLASSES+=			fix-eg-path
SUBST_STAGE.fix-eg-path=	pre-configure
SUBST_MESSAGE.fix-eg-path=	Fixing examples path.
SUBST_FILES.fix-eg-path=	etc/CMakeLists.txt
SUBST_SED.fix-eg-path=		-e 's,/etc/xdg/termit,${EGDIR},g'

## fix the config dir
SUBST_CLASSES+=			fix-conf-path
SUBST_STAGE.fix-conf-path=	pre-configure
SUBST_MESSAGE.fix-conf-path=	Fixing config files path.
SUBST_FILES.fix-conf-path=	src/lua_conf.c
SUBST_SED.fix-conf-path=	-e 's,/etc/xdg,${PKG_SYSCONFDIR},g'

## manage the config files
CONF_FILES=	${EGDIR}/colormaps.lua ${PKG_SYSCONFDIR}/colormaps.lua
CONF_FILES+=	${EGDIR}/rc.lua ${PKG_SYSCONFDIR}/rc.lua
CONF_FILES+=	${EGDIR}/utils.lua ${PKG_SYSCONFDIR}/utils.lua


.include "../../x11/vte/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
