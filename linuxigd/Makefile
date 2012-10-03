# $NetBSD: Makefile,v 1.14 2012/10/03 09:10:42 asau Exp $
#

DISTNAME=	linuxigd-1.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linux-igd/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://linux-igd.sourceforge.net/
COMMENT=	Linux UPnP Internet Gateway Device

USE_LANGUAGES=	c
USE_TOOLS+=	gmake pkg-config

.include "options.mk"

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8 share/examples

MAKE_ENV+=	LIBS=${LIBS:M*:Q}

CONF_FILES=	${PREFIX}/share/examples/upnpd.conf ${PKG_SYSCONFDIR:Q}/upnpd.conf
RCD_SCRIPTS=	linuxigd

SUBST_CLASSES+=		cfgdir
SUBST_STAGE.cfgdir=	pre-configure
SUBST_FILES.cfgdir=	globals.h etc/upnpd.conf
SUBST_SED.cfgdir=	-e 's|@CONFDIR@|${PKG_SYSCONFDIR}|'

.include "../../net/libupnp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
