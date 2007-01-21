# $NetBSD: Makefile,v 1.2 2007/01/21 09:38:10 gschwarz Exp $

DISTNAME=	weplab-0.1.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=weplab/}

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://weplab.sourceforge.net/
COMMENT=	Weplab is a tool to review the security of WEP encryption

GNU_CONFIGURE=	YES
LIBS+=		${BUILDLINK_LDADD.getopt:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t
.endif

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/weplab ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/weplab.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
