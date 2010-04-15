# $NetBSD: Makefile,v 1.1 2010/04/15 17:12:57 khorben Exp $


DISTNAME=	Init-0.0.0
PKGNAME=	deforaos-init-0.0.0
CATEGORIES=	net
MASTER_SITES=	http://www.defora.org/os/download/download/3337/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS system session

LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

RCD_SCRIPTS+=	Init

SUBST_CLASSES+=	fix-paths
SUBST_STAGE.fix-paths=	pre-install
SUBST_MESSAGE.fix-path=	Fixing absolute paths.
SUBST_FILES.fix-paths+=	../Init
SUBST_SED.fix-paths=	-e 's,"/usr/local,"${PREFIX},g'

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
