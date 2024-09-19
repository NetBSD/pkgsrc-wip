# $NetBSD: Makefile,v 1.3 2015/03/30 07:31:43 adanbsd Exp $

DISTNAME=	apinger-0.6.1
CATEGORIES=	net
MASTER_SITES=	http://freebsdcluster.org/~mich/software/

MAINTAINER=	ada@netbsdfr.org
HOMEPAGE=	http://freebsdcluster.org/~mich/software/
COMMENT=	IP/icmp based device monitoring tool
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

EGDIR=			${PREFIX}/share/examples

INSTALLATION_DIRS+=	share/examples

post-install:
	${MV} ${WRKSRC}/src/apinger.conf\
		${EGDIR}/

.include "../../mk/bsd.pkg.mk"
