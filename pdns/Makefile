# $NetBSD: Makefile,v 1.1.1.1 2003/06/27 02:47:12 poppnk Exp $

DISTNAME=	pdns-2.9.8
CATEGORIES=	dns
MASTER_SITES=	http://downloads.powerdns.com/releases/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.powerdns.com/
COMMENT=	Modern, advanced and high performance nameserver

USE_PKGINSTALL=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-modules=""
USE_BUILDLINK2=	YES
RCD_SCRIPTS=	pdns
LDFLAGS+=	-lrt

#EGDIR=		${PREFIX}/share/examples/maradns
#CONF_FILES=	${EGDIR}/example_mararc ${PKG_SYSCONFDIR}/mararc

.include "../../devel/pth/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
