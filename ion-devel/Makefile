# $NetBSD: Makefile,v 1.1.1.1 2003/04/03 09:27:17 cubidou Exp $
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

.include "../../mk/bsd.pkg.mk"
