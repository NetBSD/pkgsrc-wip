# $NetBSD: Makefile,v 1.5 2011/02/28 14:53:17 thomasklausner Exp $
#

DISTNAME=	pmk-0.10.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
CONFIGURE_SCRIPT=	pmkcfg.sh

CONFIGURE_ENV+=		SYSCONFDIR=${PKG_SYSCONFBASEDIR}
CONFIGURE_ENV+=		CONFDIR=${PKG_SYSCONFSUBDIR}
###
### This variable seems strange to me ... and barfs on -Wl,[arg]
###
CONFIGURE_ENV+=		CLDFLAGS=${LDFLAGS:S/-Wl,//g:Q}

MAKE_ENV+=		DESTDIR=${DESTDIR}
MAKE_ENV+=		PREMAKE=${PKGBASE}

MAKEFLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}

PMK_USER?=		_pmk
PMK_GROUP?=		_pmk

PKG_USERS=		${PMK_USER}:${PMK_GROUP}
PKG_GROUPS=		${PMK_GROUP}

PKG_SYSCONFSUBDIR=	${PKGBASE}

.include "../../mk/bsd.pkg.mk"
