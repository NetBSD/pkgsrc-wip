# $NetBSD$

DISTNAME=	go-jsonnet-0.22.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jsonnet.org/
COMMENT=	Implementation of Jsonnet in pure Go
LICENSE=	apache-2.0

CONFLICTS+=	jsonnet-[0-9]*

USE_LANGUAGES=	c c++

post-install:
.for f in c-bindings dumpstdlibast jsonnet-lint
	${RM} ${DESTDIR}${PREFIX}/bin/${f}
.endfor

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
