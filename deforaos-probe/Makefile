# $NetBSD: Makefile,v 1.3 2012/09/28 21:24:35 asau Exp $

DISTNAME=	Probe-0.0.2
PKGNAME=	deforaos-probe-0.0.2
CATEGORIES=	net
MASTER_SITES=	http://www.defora.org/os/download/download/3335/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS system monitoring infrastructure

LICENSE=	gnu-gpl-v3

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

PKG_GROUPS+=	probe
PKG_USERS+=	probe:probe
PKG_USERS+=	damon:probe
PKG_HOME.damon=	${VARBASE}/damon

RCD_SCRIPTS+=	DaMon
RCD_SCRIPTS+=	Probe

SUBST_CLASSES+=	fix-paths
SUBST_STAGE.fix-paths=	pre-install
SUBST_MESSAGE.fix-path=	Fixing absolute paths.
SUBST_FILES.fix-paths+=	../DaMon
SUBST_FILES.fix-paths+=	../Probe
SUBST_SED.fix-paths=	-e 's,"/usr/local,"${PREFIX},g'

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
