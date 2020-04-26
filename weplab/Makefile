# $NetBSD: Makefile,v 1.6 2012/10/07 20:11:07 asau Exp $

DISTNAME=	weplab-0.1.5
CATEGORIES=	security
MASTER_SITES=	https://dl.packetstormsecurity.net/wireless/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20170622004051/http://weplab.sourceforge.net/
COMMENT=	Weplab is a tool to review the security of WEP encryption
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
LIBS+=		${BUILDLINK_LDADD.getopt:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/weplab ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/weplab.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
