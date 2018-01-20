# $NetBSD$

DISTNAME=	rclone-1.39
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ncw/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rclone.org/
COMMENT=	Rsync for cloud storage
LICENSE=	mit

WRKSRC=		${WRKDIR}/src/github.com/ncw/rclone

.include "../../lang/go/version.mk"

BUILD_DEPENDS+=		go-${GO_VERSION}*:../../lang/go

MAKE_ENV+=		GOPATH=${WRKDIR}:${PREFIX}/gopkg

INSTALLATION_DIRS+=	bin share/doc/rclone

post-extract:
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/${DISTNAME}/* ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	    go build --ldflags "-s -X github.com/ncw/rclone/fs.Version=${PKGVERSION_NOREV}" -o bin/rclone

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rclone ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/MANUAL.html ${DESTDIR}${PREFIX}/share/doc/rclone
	${INSTALL_DATA} ${WRKSRC}/MANUAL.txt ${DESTDIR}${PREFIX}/share/doc/rclone

.include "../../mk/bsd.pkg.mk"
