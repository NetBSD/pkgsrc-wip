# $NetBSD: Makefile,v 1.14 2008/08/06 13:50:30 yazzy Exp $
#

DISTNAME=	enlightenment-0.16.999.043
PKGNAME=	e17-0.16.999.043
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-05-19/ \
		http://www.ezunix.org/pkgsrc/e17/snapshots/2008-05-19/ \
                http://jfranz.users.bsdprojects.net/pkgsrc/e17/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Enlightenment Window Manager, Development Release

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config automake autoconf
USE_DIRS+=	xdg-1.4

EGDIR=		${PREFIX}/share/examples/enlightenment
CONF_FILES=	${EGDIR}/sysactions.conf \
		${PKG_SYSCONFDIR}/etc/enlightenment/sysactions.conf

CONFIGURE_ARGS+=	--enable-zoom --enable-fsstd
CONFIGURE_ARGS+=	--with-imlib2

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/data/etc/sysactions.conf ${EGDIR}

PKG_OPTIONS_VAR=	PKG_OPTIONS.e17
PKG_SUPPORTED_OPTIONS=	dbus

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
.	include	"../../wip/edbus/buildlink3.mk"
.endif

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/eet/buildlink3.mk"
.include "../../wip/efreet/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
