# $NetBSD: Makefile,v 1.6 2006/09/27 12:13:47 ghen Exp $

MOZILLA=		firefox
MOZ_EXTRA=		2
MOZ_VER=		2.0${SUB_VER}
SUB_VER=		beta2
MOZ_DISTVER=		${MOZ_VER:S/beta/b/}

HOMEPAGE=		http://www.mozilla.org/projects/bonecho/
COMMENT=		Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=		${MOZILLA}/${MOZ_DISTDIR}
# binary package is built against GTK2
MOZ_GTK2=		YES

ONLY_FOR_PLATFORM+=	Linux-*-i386

WRKSRC=			${WRKDIR}/firefox

.include "../../www/seamonkey-bin/Makefile.common"
