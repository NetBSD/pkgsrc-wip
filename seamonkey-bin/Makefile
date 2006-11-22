# $NetBSD: Makefile,v 1.3 2006/11/22 12:53:15 ghen Exp $

MOZILLA=		seamonkey
MOZ_VER=		1.1beta
MOZ_DISTVER=		1.1b
DISTDIR=		${MOZ_DISTVER}

HOMEPAGE=		http://www.mozilla.org/projects/seamonkey/releases/${MOZ_DISTVER}.html
COMMENT=		Full featured gecko-based browser (binary package)

DIST_SUBDIR=		${MOZILLA}/${MOZ_DISTDIR}

MOZ_GTK2=		YES

ONLY_FOR_PLATFORM+=	Linux-*-i386

.include "../../wip/seamonkey-bin/Makefile.common"
