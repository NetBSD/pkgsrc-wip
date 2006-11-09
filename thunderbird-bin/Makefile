# $NetBSD: Makefile,v 1.4 2006/11/09 00:06:05 dhowland Exp $

MOZILLA=	thunderbird
MOZ_VER=	1.5.0.8
MOZ_DISTVER=	${MOZ_VER}

HOMEPAGE=	http://www.mozilla.com/projects/thunderbird/
COMMENT=	Redesign of the Mozilla mail client (binary pkg)

DIST_SUBDIR=	${MOZILLA}/${MOZ_DISTDIR}
# binary package is built against GTK2
MOZ_GTK2=	YES

ONLY_FOR_PLATFORM+=	Linux-*-i386

.include "../../www/seamonkey-bin/Makefile.common"
