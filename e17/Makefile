# $NetBSD: Makefile,v 1.20 2009/03/04 17:47:43 minskim Exp $
#

DISTNAME=	enlightenment-0.16.999.050
PKGNAME=	${DISTNAME:S/enlightenment/e17/}
CATEGORIES=	x11
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-09-25/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Enlightenment Window Manager, Development Release

DEPENDS+=	evas-eet>=0.9.9:../../graphics/evas-eet
DEPENDS+=	evas-jpeg>=0.9.9:../../graphics/evas-jpeg
DEPENDS+=	evas-png>=0.9.9:../../graphics/evas-png

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config automake autoconf
USE_DIRS+=	xdg-1.4

PKG_SYSCONFSUBDIR=	enlightenment
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/enlightenment
CONF_FILES=	${EGDIR}/sysactions.conf \
		${PKG_SYSCONFDIR}/sysactions.conf

CONFIGURE_ARGS+=	--enable-zoom --enable-fsstd
CONFIGURE_ARGS+=	--with-imlib2
CONFIGURE_ENV+=		MODULE_ARCH="${LOWER_OPSYS}-${MACHINE_ARCH}"

INSTALLATION_DIRS=	${EGDIR}

pre-install:
	${INSTALL_DATA} ${WRKSRC}/data/etc/sysactions.conf ${DESTDIR}${EGDIR}

PKGCONFIG_OVERRIDE=	enlightenment.pc.in

PKG_OPTIONS_VAR=	PKG_OPTIONS.e17
PKG_SUPPORTED_OPTIONS=	dbus

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
.	include	"../../wip/edbus/buildlink3.mk"
.endif

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../devel/eet/buildlink3.mk"
.include "../../wip/efreet/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/evas-buffer/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
