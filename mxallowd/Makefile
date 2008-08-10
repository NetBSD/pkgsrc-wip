# $NetBSD: Makefile,v 1.1.1.1 2008/08/10 15:48:45 mstapelberg Exp $

CATEGORIES=mail
DISTNAME=mxallowd-1.6
HOMEPAGE=http://michael.stapelberg.de/mxallowd
COMMENT=Anti-Spam-Daemon using pf/pflog

HAS_CONFIGURE=YES
USE_TOOLS+=gmake
CONFIGURE_ARGS+=--prefix=/usr/pkg
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc
CONFIGURE_ARGS+=--mandir=${PREFIX}/${PKGMANDIR:Q}
CONF_FILES=${PREFIX}/share/doc/mxallowd/samples/mxallowd.conf ${PKG_SYSCONFDIR}/mxallowd.conf
RCD_SCRIPTS+=mxallowd

MASTER_SITES=http://michael.stapelberg.de/mxallowd/
DISTFILES=mxallowd.1.6.tar.bz2

.include "../../mk/bsd.pkg.mk"
