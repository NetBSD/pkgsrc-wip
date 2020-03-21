# $NetBSD$

DISTNAME=	go-ghodss-yaml-1.0.0
PKGREVISION=	12
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ghodss/}
GITHUB_PROJECT=	yaml
GITHUB_TAG=	v${PKGVERSION_NOREV}

COMMENT=	YAML marshaling and unmarshaling support for Go
HOMEPAGE=	https://github.com/ghodss/yaml
LICENSE=	mit

EXTRACT_USING=	bsdtar

GO_SRCPATH=	github.com/ghodss/yaml/
GO_DIST_BASE=	yaml-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../devel/go-yaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
