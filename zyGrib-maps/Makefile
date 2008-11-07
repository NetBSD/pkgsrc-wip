# $NetBSD: Makefile,v 1.1.1.1 2008/11/07 12:35:14 plunky Exp $
#

DISTNAME=	zyGrib-maps-2
CATEGORIES=	geography
MASTER_SITES=	http://zygrib.free.fr/files/
DISTFILES=	zyGrib_maps2.tgz

MAINTAINER=	plunky@rya-online.net
HOMEPAGE=	http://zygrib.free.fr/
COMMENT=	High resolution map files for zyGrib

#LICENSE=	gnu-gpl

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	share/zyGrib/maps/gshhs

INSTALL_FILES=	maps/gshhs/gshhs_0.rim
INSTALL_FILES+=	maps/gshhs/gshhs_1.rim
INSTALL_FILES+=	maps/gshhs/rangs_0.cat
INSTALL_FILES+=	maps/gshhs/rangs_0.cel
INSTALL_FILES+=	maps/gshhs/rangs_1.cat
INSTALL_FILES+=	maps/gshhs/rangs_1.cel
INSTALL_FILES+=	maps/gshhs/wdb_borders_f.b
INSTALL_FILES+=	maps/gshhs/wdb_borders_h.b
INSTALL_FILES+=	maps/gshhs/wdb_rivers_f.b
INSTALL_FILES+=	maps/gshhs/wdb_rivers_h.b

DEPENDS+=	zyGrib>=2.0:../../wip/zyGrib

do-configure:

do-build:

do-install:
.for f in ${INSTALL_FILES}
	${INSTALL_DATA} ${WRKDIR}/${f} ${DESTDIR}${PREFIX}/share/zyGrib/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
