# $NetBSD: Makefile,v 1.7 2012/10/03 21:32:48 asau Exp $

DISTNAME=		orion-0.2
CATEGORIES=		wm
MASTER_SITES=		http://ftp.scsh.net/pub/scsh/packages/orion-wm/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://orion.antidesktop.org/
COMMENT=		Orion - a window manager for X written in Scheme

#
# XXX; This is just nasty.
#
BUILD_DEPENDS+=		scsh>=0.6:../../shells/scsh
BUILD_DEPENDS+=		scsh-install-lib>=1:../../wip/scsh-install-lib
DEPENDS+=		sunterlib-*:../../wip/sunterlib
DEPENDS+=		scx-*:../../wip/scx


NO_BUILD=		yes

#
# Default to 80 Mb (20.000.000 cells, every cell is 4 bytes):
# Changing this would make it slower or faster. (the default if we
#  wouldn't do this hack would be 20 Mb)
#
HEAP_SIZE=		20000000
SCSH_VM=		${PREFIX}/lib/scsh/scshvm
SCSH_IMAGE=		${PREFIX}/lib/scsh/scsh.image

SUBST_CLASSES+=		orion
SUBST_STAGE.orion=	post-patch
SUBST_FILES.orion=	install.scm
SUBST_VARS.orion=	HEAP_SIZE SCSH_VM SCSH_IMAGE

do-install:
	cd ${WRKSRC}; \
	./install.scm --prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
