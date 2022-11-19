# $NetBSD$

DISTNAME=	aws-nuke-2.20.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=rebuy-de/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rebuy-de/aws-nuke
COMMENT=	Nuke a whole AWS account and delete all its resources
LICENSE=	mit

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/rebuy-de/aws-nuke/v2/cmd.BuildVersion=${GITHUB_TAG} \
			-X github.com/rebuy-de/aws-nuke/v2/cmd.BuildDate= \
			-X github.com/rebuy-de/aws-nuke/v2/cmd.BuildHash= \
			-X github.com/rebuy-de/aws-nuke/v2/cmd.BuildEnvironment='

INSTALLATION_DIRS+=	share/doc/aws-nuke
INSTALLATION_DIRS+=	share/examples/aws-nuke

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/aws-nuke
	${INSTALL_DATA} ${WRKSRC}/config/* ${DESTDIR}${PREFIX}/share/examples/aws-nuke

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
