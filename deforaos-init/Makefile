# $NetBSD: Makefile,v 1.3 2015/01/27 00:10:05 khorben Exp $


DISTNAME=	Init-0.0.0
PKGNAME=	deforaos-init-0.0.0
CATEGORIES=	net
MASTER_SITES=	https://www.defora.org/os/download/download/3337/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS system session

LICENSE=	gnu-gpl-v3

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

RCD_SCRIPTS+=	Init

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	pre-install
SUBST_MESSAGE.fix-path=	Fixing absolute paths.
SUBST_FILES.fix-paths+=	../Init
SUBST_SED.fix-paths=	-e 's,"/usr/local,"${PREFIX},g'

.include "../../devel/deforaos-libsystem/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
