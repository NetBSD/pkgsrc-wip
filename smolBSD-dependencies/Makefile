# $NetBSD$

DISTNAME=	smolBSD-dependencies-2.7
CATEGORIES=	misc
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NetBSDfr/smolBSD
COMMENT=	Meta Package for smolBSD dependencies
LICENSE=	public-domain

DEPENDS+=	curl>=0:../../www/curl
DEPENDS+=	qemu>=0:../../emulators/qemu
DEPENDS+=	sudo>=0:../../security/sudo
# for uuidgen
DEPENDS+=	libuuid>=0:../../devel/libuuid
# nm: assumed in base
DEPENDS+=	lsof>=0:../../sysutils/lsof
DEPENDS+=	jq>=0:../../devel/jq
# optional:
DEPENDS+=	socat>=0:../../net/socat
DEPENDS+=	picocom>=0:../../comms/picocom

USE_TOOLS+=	git:run

META_PACKAGE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "Darwin"
DEPENDS+=	bmake>=0:../../devel/bmake
.endif
.if ${OPSYS} == "Linux"
DEPENDS+=	bsdtar>=0:../../archivers/bsdtar
# for sgdisk
DEPENDS+=	gptfdisk>=0:../../wip/gptfdisk
.endif

.include "../../mk/bsd.pkg.mk"
