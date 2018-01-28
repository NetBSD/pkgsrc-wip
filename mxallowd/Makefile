# $NetBSD: Makefile,v 1.4 2012/10/03 15:10:00 asau Exp $

CATEGORIES=	mail
DISTNAME=	mxallowd-1.7
HOMEPAGE=	http://michael.stapelberg.de/mxallowd
COMMENT=	Anti-Spam-Daemon using pf/pflog

HAS_CONFIGURE=		YES
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--prefix=/usr/pkg
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONF_FILES=		${PREFIX}/share/doc/mxallowd/samples/mxallowd.conf ${PKG_SYSCONFDIR}/mxallowd.conf
RCD_SCRIPTS+=		mxallowd

MASTER_SITES=	http://michael.stapelberg.de/mxallowd/
DISTFILES=	mxallowd.1.7.tar.bz2

.include "../../mk/bsd.pkg.mk"
