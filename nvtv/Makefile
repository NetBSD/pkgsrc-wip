# $NetBSD: Makefile,v 1.1.1.1 2003/03/26 20:40:41 cubidou Exp $

DISTNAME=	nvtv-0.4.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nv-tv-out/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://sourceforge.net/projects/nv-tv-out/
COMMENT=	tool to manipulate TV-Out settings on NVidia cards

ONLY_FOR_PLATFORM=      NetBSD-*-i386

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES

WRKSRC=		${WRKDIR}/nvtv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nvtvd ${WRKSRC}/src/nvtv ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nvtv
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/FAQ ${WRKSRC}/doc/USAGE \
		${WRKSRC}/doc/chips.txt \
		${WRKSRC}/doc/overview.txt ${WRKSRC}/doc/timing.txt \
		${PREFIX}/share/doc/nvtv
	${INSTALL_MAN} ${WRKSRC}/doc/man/nvtvd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/man/nvtv.1x ${PREFIX}/man/man8/nvtv.8

.include "../../sysutils/pciutils/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
