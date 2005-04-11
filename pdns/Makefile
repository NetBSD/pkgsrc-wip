# $NetBSD: Makefile,v 1.4 2005/04/11 21:14:44 tvierling Exp $

DISTNAME=		pdns-2.9.8
CATEGORIES=		net
MASTER_SITES=	http://downloads.powerdns.com/releases/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.powerdns.com/
COMMENT=		Modern, advanced and high performance nameserver

USE_PKGINSTALL=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-modules=""
RCD_SCRIPTS=	pdns
LDFLAGS+=		-lrt

#EGDIR=		${PREFIX}/share/examples/maradns
#CONF_FILES=	${EGDIR}/example_mararc ${PKG_SYSCONFDIR}/mararc

.include "../../mk/bsd.pkg.mk"
