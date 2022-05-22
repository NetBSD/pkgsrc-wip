# $NetBSD$

DISTNAME=	yq-4.25.1
PKGNAME=	${DISTNAME:C/^/go/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mikefarah/}
GITHUB_PROJECT=	yq
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mikefarah.gitbook.io/yq/
COMMENT=	Portable command-line YAML, JSON and XML processor
LICENSE=	mit

GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/yq ${DESTDIR}${PREFIX}/bin/goyq

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
