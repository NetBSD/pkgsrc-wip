# $NetBSD: Makefile,v 1.4 2004/01/05 10:30:00 cubidou Exp $
#

DISTNAME=	ion-devel-20031211
PKGNAME=	${DISTNAME:S/-devel//}
CATEGORIES=	wm x11
MASTER_SITES=	http://modeemi.fi/~tuomov/dl/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://iki.fi/~tuomov/ion/
COMMENT=	Keyboard friendly tiling window manager

BUILDLINK_DEPENDS.ltdl=	libtool-base>=1.4.20010614nb19

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
USE_X11=	YES
USE_GMAKE=	YES

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

post-patch:
	${SED} -e s,@@PREFIX@@,${PREFIX}, -e s,@@X11BASE@@,${X11BASE},	\
	    -e s,@@LUADIR@@,${BUILDLINK_PREFIX.lua},			\
	    -e s,@@LIBTOOL@@,${BUILDLINK_PREFIX.ltdl}/bin/libtool,	\
	    ${WRKSRC}/system.mk > ${WRKSRC}/system.mk.tmp
	${MV} ${WRKSRC}/system.mk.tmp ${WRKSRC}/system.mk

.include "../../lang/lua/buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
