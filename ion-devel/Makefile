# $NetBSD: Makefile,v 1.2 2003/04/09 17:52:52 cubidou Exp $
#

DISTNAME=	ion-devel-20030327
PKGNAME=	${DISTNAME:S/-devel//}
CATEGORIES=	x11 wm
MASTER_SITES=	http://modeemi.fi/~tuomov/dl/

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://iki.fi/~tuomov/ion/
COMMENT=	keyboard friendly tiling window manager

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
USE_X11=	YES
USE_GMAKE=	YES

MAKE_ENV+=	X11_PREFIX=${BUILDLINK_X11_DIR}

PKG_SYSCONFSUBDIR=	ion
EGDIR=			${PREFIX}/share/examples/ion
EGFILES=		common-frame-bindings.conf draw.conf \
			floatws.conf ioncore.conf ioncore-bindings.conf \
			ionws.conf kludges.conf look-blackwheat.conf \
			look-brownsteel.conf look-clean.conf \
			look-dusky.conf look-greyviolet.conf look-ios.conf \
			look-simpleblue.conf look-wheat.conf query.conf \
			ioncore-example.conf
.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/$f ${PKG_SYSCONFDIR}/$f
.endfor
.undef f

post-patch:
	${SED} -e s,@@PREFIX@@,${PREFIX}, -e s,@@X11BASE@@,${X11BASE}, \
	    ${WRKSRC}/system.mk > ${WRKSRC}/system.mk.tmp
	${MV} ${WRKSRC}/system.mk.tmp ${WRKSRC}/system.mk

.include "../../mk/bsd.pkg.mk"
