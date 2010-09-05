# $NetBSD: Makefile,v 1.5 2010/09/05 12:04:17 gschwarz Exp $

DISTNAME=	weplab-0.1.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=weplab/}

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://weplab.sourceforge.net/
COMMENT=	Weplab is a tool to review the security of WEP encryption
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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
