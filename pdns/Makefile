# $NetBSD: Makefile,v 1.6 2006/03/14 01:28:08 jlamwww Exp $

DISTNAME=		pdns-2.9.8
CATEGORIES=		net
MASTER_SITES=	http://downloads.powerdns.com/releases/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.powerdns.com/
COMMENT=		Modern, advanced and high performance nameserver

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-modules=""
RCD_SCRIPTS=	pdns
LDFLAGS+=		-lrt

#EGDIR=		${PREFIX}/share/examples/maradns
#CONF_FILES=	${EGDIR}/example_mararc ${PKG_SYSCONFDIR}/mararc

.include "../../mk/bsd.pkg.mk"
