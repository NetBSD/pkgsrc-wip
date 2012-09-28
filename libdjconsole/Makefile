# $NetBSD: Makefile,v 1.4 2012/09/28 03:57:46 othyro Exp $
#

DISTNAME=	libdjconsole-0.1.3
PKGREVISION=	1
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

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	libdjconsole.pc.in

EGDIR=			${PREFIX}/share/examples/udev/rules.d
CONF_FILES+=		${EGDIR}/45-hpdjconsole.rules ${PKG_SYSCONFDIR}/udev/rules.d/45-hpdjconsole.rules
INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/udev/rules.d/ ${EGDIR}


pre-install:
	${INSTALL_DATA} ${WRKSRC}/45-hpdjconsole.rules ${DESTDIR}${EGDIR}/45-hpdjconsole.rules


.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
