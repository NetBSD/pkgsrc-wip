# $NetBSD$

DISTNAME=	go-amqp-1.0.0
GITHUB_PROJECT=	amqp
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=streadway/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/streadway/amqp/
COMMENT=	Go client for AMQP
LICENSE=	2-clause-bsd

GO_SRCPATH=	github.com/streadway/amqp
GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
