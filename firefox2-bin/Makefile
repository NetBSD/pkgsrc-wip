# $NetBSD: Makefile,v 1.1.1.1 2006/03/30 06:42:55 ghen Exp $

MOZILLA=		firefox2
MOZ_VER=		2.0alpha1
MOZ_DISTVER=		${MOZ_VER}

HOMEPAGE=		http://www.mozilla.org/projects/bonecho/
COMMENT=		Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=		${MOZILLA}/${MOZ_DISTDIR}
# binary package is built against GTK2
MOZ_GTK2=		YES

ONLY_FOR_PLATFORM+=	Linux-*-i386

WRKSRC=			${WRKDIR}/firefox

.include "../../www/mozilla-bin/Makefile.common"
