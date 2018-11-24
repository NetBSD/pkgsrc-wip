# $NetBSD$

GITHUB_PROJECT= haxm
GITHUB_TAG=     226b5a8ef3b79ca3d235a629a83a4a2168c11e36
DISTNAME=       haxm-0.${GITHUB_TAG}
CATEGORIES=     emulators
MASTER_SITES=   ${MASTER_SITE_GITHUB:=intel/}

MAINTAINER=	kamil@NetBSD.org
HOMEPAGE=	https://github.com/intel/haxm/
COMMENT=	Intel Hardware Accelerated Execution Manager
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/haxm-${GITHUB_TAG}

PKG_FAIL_REASON=	"Build manually and install manually:"
PKG_FAIL_REASON+=	"cd platforms/netbsd && make"
PKG_FAIL_REASON+=	"modload ./intel-hax"
PKG_FAIL_REASON+=	"cd /dev && mknod HAX c 220 0"
PKG_FAIL_REASON+=	"cd /dev && mkdir hax_vm hax_vm00"
PKG_FAIL_REASON+=	"cd /dev/hax_vm && mknod vm00 c 222 0"
PKG_FAIL_REASON+=	"cd /dev/hax_vm00 && mknod vcpu00 c 221 0"
PKG_FAIL_REASON+=	"qemu-system-x86_64 --enable-hax"

.include "../../mk/bsd.pkg.mk"
