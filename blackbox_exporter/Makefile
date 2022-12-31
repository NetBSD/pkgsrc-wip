# $NetBSD: Makefile,v 1.45 2022/12/25 17:46:15 bsiegert Exp $

DISTNAME=	blackbox_exporter-0.23.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}
CATEGORIES=	sysutils
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://github.com/prometheus/blackbox_exporter
COMMENT=	Prometheus blackbox exporter
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/prometheus/common/version.Version=${PKGVERSION_NOREV} \
			-X github.com/prometheus/common/version.Revision=${PKGREVISION} \
			-X github.com/prometheus/common/version.Branch=${GITHUB_TAG}'

DOCDIR=		share/doc/blackbox_export
EGDIR=		share/examples/blackbox_export

INSTALLATION_DIRS+=	${DOCDIR}
INSTALLATION_DIRS+=	${EGDIR}

.include "go-modules.mk"

post-install:
.for f in CONFIGURATION.md README.md
	${INSTALL_DATA} ${WRKSRC}/$f \
		${DESTDIR}${PREFIX}/${DOCDIR}/$f
.endfor
	${INSTALL_DATA} ${WRKSRC}/blackbox.yml \
		${DESTDIR}${PREFIX}/${EGDIR}/blackbox.yml

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
