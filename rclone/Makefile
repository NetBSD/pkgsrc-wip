# $NetBSD$

DISTNAME=	rclone-1.43.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ncw/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://rclone.org/
COMMENT=	Rsync for cloud storage
LICENSE=	mit

GO_DIST_BASE=		${DISTNAME}
GO_SRCPATH=		github.com/ncw/rclone

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

CHECK_RELRO_SKIP+=	bin/rclone

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/rclone ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rclone.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
