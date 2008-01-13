# $NetBSD: Makefile,v 1.1 2008/01/13 10:32:52 bsadewitz Exp $
#

DISTNAME=	pmk-0.10.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmk/}

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://pmk.sourceforge.net/
COMMENT=	Pre-make kit

PKG_DESTDIR_SUPPORT=	destdir

HAS_CONFIGURE=		yes
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	-p ${PREFIX}
###
### XXX Do we want the "privsep user"?
###
#CONFIGURE_ARGS+=	-U ${PMK_USER}
CONFIGURE_SCRIPT= 	pmkcfg.sh

CONFIGURE_ENV+=		SYSCONFDIR=${PKG_SYSCONFBASEDIR:Q}
CONFIGURE_ENV+=		CONFDIR=${PKG_SYSCONFSUBDIR:Q}
###
### This variable seems strange to me ... and barfs on -Wl,[arg]
###
CONFIGURE_ENV+=		CLDFLAGS=${LDFLAGS:S/-Wl,//g:M*:Q}

MAKE_ENV+=		DESTDIR=${DESTDIR:Q}
MAKE_ENV+=		PREMAKE=${PKGBASE:Q}

PMK_USER?=		_pmk
PMK_GROUP?=		_pmk

PKG_USERS=		${PMK_USER}:${PMK_GROUP}
PKG_GROUPS=		${PMK_GROUP}

PKG_SYSCONFSUBDIR=	${PKGBASE}

.include "../../mk/bsd.pkg.mk"
