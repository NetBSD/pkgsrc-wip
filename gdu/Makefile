# $NetBSD$

DISTNAME=	gdu-5.37.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=dundee/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	tallirishllama@gmail.com
HOMEPAGE=	https://github.com/dundee/gdu/
COMMENT=	Pretty fast disk usage analyzer written in Go
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

GO_BUILD_PATTERN+=	./cmd/gdu

# Rename the executable as 'gdu-go' to avoid conflicting with 'gdu'
# from GNU coreutils (sysutils/coreutils).
post-install:
	${RUN} mv ${DESTDIR}${PREFIX}/bin/gdu ${DESTDIR}${PREFIX}/bin/gdu-go

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
