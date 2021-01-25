# $NetBSD$

DISTNAME=	go-client_model-0.2.0
GITHUB_PROJECT=	client_model
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	category
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/prometheus/client_model/
COMMENT=	Data model artifacts for Prometheus
LICENSE=	apache-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/prometheus/client_model

.include "../../devel/go-protobuf/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
