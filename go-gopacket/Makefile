# $NetBSD$

DISTNAME=	gopacket-1.1.14
PKGNAME=	go-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
CATEGORIES=	net
GITHUB_PROJECT=	${PKGBASE:S/^go-//}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/google/gopacket
COMMENT=	Packet processing capabilities for Go
LICENSE=	modified-bsd

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	${HOMEPAGE:S,https://,,}

.include "../../devel/go-sys/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/go/go-package.mk"

.PHONY: post-extract
post-extract: exclude-subpackages
exclude-subpackages:
.for p in examples/pfdump pfring
	${RM} -r ${WRKDIR}/${DISTNAME}/${p}
.endfor

.include "../../mk/bsd.pkg.mk"
