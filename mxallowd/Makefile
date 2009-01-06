# $NetBSD: Makefile,v 1.2 2009/01/06 12:10:17 mstapelberg Exp $

CATEGORIES=mail
DISTNAME=mxallowd-1.7
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
DISTFILES=mxallowd.1.7.tar.bz2

.include "../../mk/bsd.pkg.mk"
