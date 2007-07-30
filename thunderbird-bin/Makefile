# $NetBSD: Makefile,v 1.5 2007/07/30 15:49:11 jlamwww Exp $

MOZILLA=	thunderbird
MOZ_VER=	1.5.0.8
MOZ_DISTVER=	${MOZ_VER}

HOMEPAGE=	http://www.mozilla.com/projects/thunderbird/
COMMENT=	Redesign of the Mozilla mail client (binary pkg)

DIST_SUBDIR=	${MOZILLA}/${MOZ_DISTDIR}
# binary package is built against GTK2
MOZ_GTK2=	YES

EMUL_PLATFORMS=		linux-i386

.include "../../www/seamonkey-bin/Makefile.common"
