# $NetBSD: Makefile,v 1.2 2004/01/25 02:33:11 grantbeattie Exp $

DISTNAME=	pdns-2.9.8
CATEGORIES=	dns
MASTER_SITES=	http://downloads.powerdns.com/releases/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.powerdns.com/
COMMENT=	Modern, advanced and high performance nameserver

USE_PKGINSTALL=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-modules=""
USE_BUILDLINK2=	YES
RCD_SCRIPTS=	pdns
LDFLAGS+=	-lrt

#EGDIR=		${PREFIX}/share/examples/maradns
#CONF_FILES=	${EGDIR}/example_mararc ${PKG_SYSCONFDIR}/mararc

.include "../../devel/pth/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
