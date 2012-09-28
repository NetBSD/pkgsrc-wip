# $NetBSD: Makefile,v 1.29 2012/09/28 22:07:28 asau Exp $
#

DISTNAME=	enlightenment-0.16.999.55225
PKGNAME=	${DISTNAME:S/enlightenment/e17/}
CATEGORIES=	x11
MASTER_SITES=	http://download.enlightenment.org/snapshots/2010-12-03/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Enlightenment Window Manager, Development Release

DEPENDS+=	evas-eet>=1.1.0:../../graphics/evas-eet
DEPENDS+=	evas-jpeg>=1.1.0:../../graphics/evas-jpeg
DEPENDS+=	evas-png>=1.1.0:../../graphics/evas-png

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config automake autoconf

PKG_SYSCONFSUBDIR=	enlightenment
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/enlightenment
CONF_FILES=	${EGDIR}/sysactions.conf \
		${PKG_SYSCONFDIR}/sysactions.conf

CONFIGURE_ARGS+=	--enable-zoom --enable-fsstd
CONFIGURE_ENV+=		MODULE_ARCH="${LOWER_OPSYS}-${MACHINE_ARCH}"

INSTALLATION_DIRS=	${EGDIR}

pre-install:
	${INSTALL_DATA} ${WRKSRC}/data/etc/sysactions.conf ${DESTDIR}${EGDIR}

PKGCONFIG_OVERRIDE=	enlightenment.pc.in

.include "../../devel/ecore/buildlink3.mk"
.include "../../sysutils/edbus/buildlink3.mk"
.include "../../graphics/edje/buildlink3.mk"
.include "../../devel/eet/buildlink3.mk"
.include "../../sysutils/efreet/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/evas-buffer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
