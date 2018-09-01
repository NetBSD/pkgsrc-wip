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

SUBST_CLASSES+=		ldflags
SUBST_STAGE.ldflags=	pre-configure
SUBST_MESSAGE.ldflags=	Set LDFLAGS for cgo.
SUBST_FILES.ldflags=	pcap/pcap.go
SUBST_SED.ldflags=	-e 's, LDFLAGS:, LDFLAGS: -L${BUILDLINK_PREFIX.libpcap}/lib,g'

PLIST_VARS+=	afpacket bsdbpf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly"
PLIST.bsdbpf=	yes
.elif ${OPSYS} == "Linux"
PLIST.afpacket=	yes

.include "../../net/go-net/buildlink3.mk"
.endif

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
