# $NetBSD: Makefile,v 1.2 2004/02/22 16:48:17 tomhensel Exp $

DISTNAME=	ion-2-${_ION2_VER}
PKGNAME=	${DISTNAME:S/-2/2/:S/$_ION2_VER//}
CATEGORIES=	wm x11
MASTER_SITES=	http://modeemi.fi/~tuomov/dl/

MAINTAINER=	tom@replic8.net
HOMEPAGE=	http://modeemi.fi/~tuomov/ion/
COMMENT=	Tiling tabbed window manager designed with keyboard users in mind

CONFLICTS=	ion

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
USE_X11=	YES
USE_GNU_TOOLS+=	make

_ION2_VER=		20040207

PKG_SYSCONFSUBDIR=	ion
EGDIR=			${PREFIX}/share/examples/ion
EGFILES=		floatws.lua ion-bindings.lua ion-menus.lua	\
			ion.lua ionws.lua kludges.lua			\
			look-clean.lua look-cleanios.lua		\
			look-cleanviolet.lua look-dusky.lua		\
			look-greyviolet.lua look-ios.lua		\
			look-simpleblue.lua look-wheat2.lua menu.lua	\
			query.lua draw.lua pwm.lua
.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/$f ${PKG_SYSCONFDIR}/$f
.endfor
.undef f

ION_INCLUDE_DIR=	${PREFIX}/include/ion

post-patch:
	${SED} -e s,@@PREFIX@@,${PREFIX}, -e s,@@X11BASE@@,${X11BASE},	\
	    -e s,@@LUADIR@@,${BUILDLINK_PREFIX.lua},			\
	    -e s,@@LIBTOOL@@,${BUILDLINK_PREFIX.ltdl}/bin/libtool,	\
	    ${WRKSRC}/system.mk > ${WRKSRC}/system.mk.tmp
	${MV} ${WRKSRC}/system.mk.tmp ${WRKSRC}/system.mk

post-install:
	${INSTALL_DATA_DIR} ${ION_INCLUDE_DIR}
	${INSTALL_DATA_DIR} ${ION_INCLUDE_DIR}/ioncore
	${INSTALL_DATA_DIR} ${ION_INCLUDE_DIR}/libtu
	${INSTALL_DATA_DIR} ${ION_INCLUDE_DIR}/luaextl
	${INSTALL_DATA} ${WRKSRC}/config.h ${ION_INCLUDE_DIR}
	${INSTALL_DATA} ${WRKSRC}/version.h ${ION_INCLUDE_DIR}
	${INSTALL_DATA} ${WRKSRC}/mkexports.lua ${ION_INCLUDE_DIR}
	${INSTALL_DATA} ${WRKSRC}/rules.mk ${ION_INCLUDE_DIR}
	${INSTALL_DATA} ${WRKSRC}/system.mk ${ION_INCLUDE_DIR}
	${INSTALL_DATA} ${WRKSRC}/system-inc.mk ${ION_INCLUDE_DIR}
	${INSTALL_DATA} ${WRKSRC}/ioncore/*.h ${ION_INCLUDE_DIR}/ioncore
	${INSTALL_DATA} ${WRKSRC}/libtu/include/libtu/*.h ${ION_INCLUDE_DIR}/libtu
	${INSTALL_DATA} ${WRKSRC}/luaextl/luaextl.h ${ION_INCLUDE_DIR}/luaextl/

.include "../../lang/lua/buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
