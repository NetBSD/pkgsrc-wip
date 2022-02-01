# $NetBSD: Makefile,v 1.11 2021/08/11 19:35:04 bsiegert Exp $

DISTNAME=		amazon-ecs-cli-1.21.0
PKGREVISION=		7
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=aws/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_CLI.html
COMMENT=		Amazon ECS Cli
LICENSE=		apache-2.0

WRKSRC=			${WRKDIR}/${DISTNAME}/ecs-cli

GO_BUILD_PATTERN=	.

INSTALLATION_DIRS+=	bin

pre-patch:
	${CP} ${FILESDIR}/go.mod ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/ecs-cli ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
