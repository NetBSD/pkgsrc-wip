#
# $NetBSD: Makefile,v 1.2 2005/02/16 16:57:39 airhead Exp $
#

DISTNAME=		orion-0.2
CATEGORIES=		wip wm
MASTER_SITES=		ftp://ftp.scsh.net/pub/scsh/packages/orion-wm/

MAINTAINER=		airhead@users.sf.net
HOMEPAGE=		http://orion.elektrubadur.se/
COMMENT=		Orion - a window manager for X written in Scheme

#
# XXX; This is just nasty.  In this case the package is the wrong-doer by
# making its own install program.
#
BUILD_DEPENDS+=		scsh-${SCSH_VERSION}.[0-9]:../../shells/scsh
BUILD_DEPENDS+=		scsh-install-lib>=1:../../wip/scsh-install-lib
DEPENDS+=		sunterlib-*:../../wip/sunterlib
DEPENDS+=		scx-*:../../wip/scx

SCSH_VERSION?=		0.6
SCSH_LIBPATH=		${PREFIX}/share/scsh-${SCSH_VERSION}/modules

NO_BUILD=		yes

do-install:
	cd ${WRKSRC}; \
	env SCSH_LIB_DIRS=\"${SCSH_LIBPATH}\" \
	    ./install.scm --prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
