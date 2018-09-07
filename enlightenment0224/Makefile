# $NetBSD: Makefile,v 0.2 2018/09/06 16:15:10 andyb Exp $

DISTNAME=	enlightenment-0.22.4
CATEGORIES=	wip
MASTER_SITES=	https://download.enlightenment.org/rel/apps/enlightenment/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	andyb@m42.one
HOMEPAGE=	https://download.enlightenment.org/rel/apps/enlightenment/
COMMENT=	Enlightenment desktop
LICENSE=	2-clause-bsd

DEPENDS+=               efl121-[0-9]*:../../wip/efl121/
DEPENDS+=               terminology-[0-9]*:../../wip/terminology/

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	enlightenment.pc.in
PKGCONFIG_OVERRIDE+=	src/modules/everything/everything.pc.in

EGDIR=			${PREFIX}/share/examples/enlightenment0224
INSTALLATION_DIRS=	share/doc/enlightenment0224

pre-install:
	${INSTALL_DATA} ${WRKSRC}/data/etc/enlightenment.menu ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/data/etc/sysactions.conf ${DESTDIR}${EGDIR}

.include "../../wip/efl121/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
