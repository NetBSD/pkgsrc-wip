# $NetBSD: Makefile,v 1.8 2006/08/27 15:00:00 obache Exp $
#

DISTNAME=	linuxigd-0.95
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linux-igd/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://linux-igd.sourceforge.net/
COMMENT=	Linux UPnP Internet Gateway Device

USE_LANGUAGES=	c
USE_TOOLS+=	gmake pkg-config

.include "options.mk"

INSTALLATION_DIRS=	${PKG_SYSCONFDIR:S|^${PREFIX}/||}/linuxigd

MAKE_ENV+=	LIBS=${LIBS:M*:Q}

CONF_FILES=	${PREFIX}/share/examples/upnpd.conf ${PKG_SYSCONFDIR:Q}/upnpd.conf
RCD_SCRIPTS=	linuxigd

SUBST_CLASSES+=		cfgdir
SUBST_STAGE.cfgdir=	pre-configure
SUBST_FILES.cfgdir=	globals.h etc/upnpd.conf
SUBST_SED.cfgdir=	-e 's|@CONFDIR@|${PKG_SYSCONFDIR}|'

.include "../../wip/libupnp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
