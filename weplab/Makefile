# $NetBSD: Makefile,v 1.1.1.1 2006/10/28 20:27:56 gschwarz Exp $

DISTNAME=	weplab-0.1.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=weplab/}

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://weplab.sourceforge.net/
COMMENT=	Weplab is a tool to review the security of WEP encryption

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/weplab ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/weplab.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
