# $NetBSD: Makefile,v 1.2 2009/03/08 00:20:21 pettai Exp $
#

DISTNAME=	dnstop-20090128
CATEGORIES=	net
MASTER_SITES=	http://dns.measurement-factory.com/tools/dnstop/src/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://dns.measurement-factory.com/tools/dnstop/
COMMENT=	Diagnose tcpdump trace for DNS queries/replies

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dnstop.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/dnstop
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/dnstop

.include "../../devel/ncurses/buildlink3.mk"
BUILDLINK_API_DEPENDS.libpcap+=		libpcap>=0.7.0
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
