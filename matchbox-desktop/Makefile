# $NetBSD: Makefile,v 1.8 2005/01/01 22:34:46 mattd Exp $
#

DISTNAME=	matchbox-desktop-0.8.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.handhelds.org/projects/matchbox/sources/matchbox-desktop/0.8/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://matchbox.handhelds.org/
COMMENT=	Desktop manager for Matchbox

USE_PKGINSTALL=	yes
USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
AUTOCONF_REQD=	2.53

PKGCONFIG_OVERRIDE=	matchbox-desktop.pc.in

CONFIGURE_ARGS+=	--enable-startup-notification

PKG_SYSCONFSUBDIR=	matchbox
EGDIR=			${PREFIX}/share/examples/matchbox-desktop
CONF_FILES=		${EGDIR}/mbdesktop_modules ${PKG_SYSCONFDIR}/mbdesktop_modules

# Regenerate files after patching. This will disappear in next version,
# patches have been sent upstream.
#
pre-configure:
	cd ${WRKSRC};							\
	${ACLOCAL};							\
	${AUTOHEADER};							\
	${AUTOMAKE} -a --foreign -i;					\
	${AUTOCONF}

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../wip/libmatchbox/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
