# $NetBSD: Makefile,v 1.7 2012/10/30 19:28:32 othyro Exp $
#

DISTNAME=	libdjconsole-0.1.3
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=djplay/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://djplay.sourceforge.net/
COMMENT=	DJ Console access library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libdjconsole.pc.in

EGDIR=			${PREFIX}/share/examples/udev/rules.d
CONF_FILES+=		${EGDIR}/45-hpdjconsole.rules ${PKG_SYSCONFDIR}/udev/rules.d/45-hpdjconsole.rules
INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/udev/rules.d/ ${EGDIR}


BUILDLINK_ABI_DEPENDS.libusb+=	libusb>=0.1.11
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
