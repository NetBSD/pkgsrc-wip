# $NetBSD: Makefile,v 0.2 2018/09/06 16:15:10 andyb Exp $

DISTNAME=       terminology-1.2.1
CATEGORIES=     wip
MASTER_SITES=   https://download.enlightenment.org/rel/apps/terminology/
EXTRACT_SUFX=   .tar.xz

MAINTAINER=     andyb@m42.one
HOMEPAGE=       https://download.enlightenment.org/rel/apps/terminology/
COMMENT=        Enlightenment terminal
LICENSE=        2-clause-bsd

DEPENDS+=       efl121-[0-9]*:../../wip/ecore121/

INSTALLATION_DIRS=      share/doc/terminology

post-install:
        ${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING \
            ${DESTDIR}${PREFIX}/share/doc/terminology

.include "../efl121/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
