#
# $NetBSD: Makefile,v 1.3 2005/02/16 22:24:26 airhead Exp $
#

DISTNAME=		orion-0.2
CATEGORIES=		wip wm
MASTER_SITES=		ftp://ftp.scsh.net/pub/scsh/packages/orion-wm/

MAINTAINER=		airhead@users.sf.net
HOMEPAGE=		http://orion.elektrubadur.se/
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
SUBST_SED.orion=	-e "s,@HEAP_SIZE@,${HEAP_SIZE},g" \
			-e "s,@SCSH_VM@,${SCSH_VM},g"     \
			-e "s,@SCSH_IMAGE@,${SCSH_IMAGE},g"

do-install:
	cd ${WRKSRC}; \
	./install.scm --prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
