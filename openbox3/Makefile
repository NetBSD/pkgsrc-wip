# $NetBSD: Makefile,v 1.8 2003/09/16 05:48:11 blef Exp $

DISTNAME=	openbox-3.0-beta3
PKGNAME=	${DISTNAME:S/-beta/beta/}
CATEGORIES=	wm x11
MASTER_SITES=	http://icculus.org/openbox/releases/

MAINTAINER=	snj@pobox.com
HOMEPAGE=	http://icculus.org/openbox/
COMMENT=	Standards compliant, light-weight and extensible window manager

BUILD_USES_MSGFMT=	YES
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
DEPENDS+=		vera-ttf>=1.10:../../fonts/vera-ttf

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_X11=		YES
USE_PKGINSTALL=		YES

PKG_SYSCONFSUBDIR?=	openbox
EGDIR=			${PREFIX}/share/examples/openbox
CONF_FILES=		${EGDIR}/rc.xml ${PKG_SYSCONFDIR}/rc.xml
CONF_FILES+=		${EGDIR}/menu.xml ${PKG_SYSCONFDIR}/menu.xml

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
