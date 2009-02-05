# $NetBSD: Makefile,v 1.1.1.1 2009/02/05 15:35:40 pettai Exp $
#

DISTNAME=	dnstop-20090128
CATEGORIES=	net
MASTER_SITES=	http://dns.measurement-factory.com/tools/dnstop/src/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://dns.measurement-factory.com/tools/dnstop/
COMMENT=	Diagnose tcpdump trace for DNS queries/replies

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dnstop.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dnstop
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/dnstop

.include "../../devel/ncurses/buildlink3.mk"
BUILDLINK_API_DEPENDS.libpcap+=		libpcap>=0.7.0
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
