# $NetBSD: Makefile,v 1.1.1.1 2006/01/07 01:53:23 cetrox Exp $
#

PKGNAME=		gtranscode-0.3
DISTNAME=		gtranscode-v0.3
CATEGORIES=		multimedia
MASTER_SITES=		http://www.fuzzymonkey.net/files/

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://fuzzymonkey.net/newfuzzy/software/gtranscode/
COMMENT=		GTK+ GUI front-end for transcode

DEPENDS+=	transcode-[0-9]*:../../multimedia/transcode

WRKSRC=		${WRKDIR}/gtranscode

do-install:
		cd ${WRKDIR}/gtranscode ; \
		${INSTALL_PROGRAM} gtranscode ${LOCALBASE}/bin

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
