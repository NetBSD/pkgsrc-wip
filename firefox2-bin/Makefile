# $NetBSD: Makefile,v 1.2 2006/05/22 16:10:00 ghen Exp $

MOZILLA=		firefox
MOZ_EXTRA=		2
MOZ_VER=		2.0alpha2
MOZ_DISTVER=		${MOZ_VER}

HOMEPAGE=		http://www.mozilla.org/projects/bonecho/
COMMENT=		Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=		${MOZILLA}/${MOZ_DISTDIR}
# binary package is built against GTK2
MOZ_GTK2=		YES

ONLY_FOR_PLATFORM+=	Linux-*-i386

WRKSRC=			${WRKDIR}/firefox

.include "../../www/mozilla-bin/Makefile.common"
