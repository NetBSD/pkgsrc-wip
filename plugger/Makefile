# $NetBSD: Makefile,v 1.4 2003/06/11 12:26:22 airhead Exp $
#

DISTNAME=	plugger-4.0
CATEGORIES=	www
MASTER_SITES=	http://fredrik.hubbe.net/plugger/
MASTER_SITES+=	ftp://ftp.netscape.com/pub/sdk/plugin/unix/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} unix-sdk-3.0b5.tar.Z

MAINTAINER=	airhead@sourceforge.net
HOMEPAGE=	http://fredrik.hubbe.net/plugger/plugger.html
COMMENT=	Plugin for multimedia types in Mozilla, Netscape and Opera

USE_X11=		YES
ALL_TARGET=		auto
USE_PKGINSTALL=		YES

EGDIR=			${PREFIX}/share/examples/plugger
CONF_FILES=		${EGDIR}/pluggerrc ${PKG_SYSCONFDIR}/pluggerrc

.include "../../mk/bsd.pkg.mk"
