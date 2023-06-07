# $NetBSD$

DISTNAME=	yet-another-cloudwatch-exporter-0.51.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=nerdswords/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nerdswords/yet-another-cloudwatch-exporter
COMMENT=	Prometheus exporter for AWS CloudWatch
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.version=${GITHUB_TAG}'
GO_BUILD_PATTERN+=	./cmd/yace

DOCDIR=		share/doc/yet-another-cloudwatch-exporter
EGDIR=		share/examples/yet-another-cloudwatch-exporter

INSTALLATION_DIRS+=	${DOCDIR}
INSTALLATION_DIRS+=	${EGDIR}


.include "go-modules.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.md ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
