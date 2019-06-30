# $NetBSD: Makefile,v 1.1 2015/06/20 19:27:51 ishit Exp $
#

DISTNAME=	pixz-1.0.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pixz/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ishit@users.sourceforge.net
HOMEPAGE=	https://github.com/vasi/pixz
COMMENT=	Parallel, indexed xz compressor
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake

DEPENDS+=	xz>=5:../../archivers/xz
BUILDLINK_API_DEPENDS.libarchive+=	libarchive>=2.8

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pixz ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pixz.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
