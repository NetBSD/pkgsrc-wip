# $NetBSD$

DISTNAME=	navidrome-0.64.2
GITID=		101145742f4762164202cb4858c9126258bdc463
CATEGORIES=	audio net www
MASTER_SITES=	${MASTER_SITE_GITHUB:=navidrome/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
# use UI assets created for FreeBSD port
MASTER_SITES.navidrome-v0.64.2.frontend.tar.gz=	https://pkg.freebsd.org/ports-distfiles/
DISTFILES+=	navidrome-v0.64.2.frontend.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.navidrome.org/
COMMENT=	Your Personal Streaming Service
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	nodejs>=0:../../lang/nodejs

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

GO_BUILD_PATTERN=	-tags=netgo,sqlite_fts5
GO_BUILD_PATTERN+=	-ldflags="-X github.com/navidrome/navidrome/consts.gitSha=$(GITID) -X github.com/navidrome/navidrome/consts.gitTag=$(PKGVERSION_NOREV)"

#.if make(create-asserts)
#ALLOW_NETWORK_ACCESS=	yes
#.endif
#
# maintainer-only: upload the result
# XXX: fails due to missing NetBSD support in one of the gazillion dependencies
#.PHONY: create-assets
#create-assets:
#	cd ${WRKSRC}/ui && \
#		${SETENV} ${MAKE_ENV} npm ci && \
#		${SETENV} ${MAKE_ENV} npm run build -- --outDir=${WRKDIR}/navidrome-fontend
#	cd ${WRKDIR} && \
#		${SETENV} ${MAKE_ENV} tar czf navidrome-${PKGVERSION_NOREV}-fontend.tar.gz navidrome-fontend

post-extract:
	${MV} ${WRKDIR}/navidrome-frontend/* ${WRKSRC}/ui/build/

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
EXTRACT_ONLY+=	navidrome-v0.64.2.frontend.tar.gz
.include "../../mk/bsd.pkg.mk"
