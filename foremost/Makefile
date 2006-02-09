# $NetBSD: Makefile,v 1.1.1.1 2006/02/09 15:33:04 lkundrak Exp $

DISTNAME=	foremost-1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://localhost/~lkundrak/

MAINTAINER=	lkundrak@skosi.org
HOMEPAGE=	http://localhost/~lkundrak/
COMMENT=	Recover various formats of files using typical data structures

.include "../../mk/bsd.prefs.mk"

EGDIR=		${PREFIX}/share/examples/foremost
CONF_FILES=	${EGDIR}/foremost.conf ${PKG_SYSCONFDIR}/foremost.conf

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../mk/bsd.pkg.mk"
