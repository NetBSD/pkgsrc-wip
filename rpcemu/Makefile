# $NetBSD: Makefile,v 1.2 2012/10/07 14:53:44 asau Exp $
#

DISTNAME=	rpcemu-0.8.8
CATEGORIES=	emulators
MASTER_SITES=	http://www.marutan.net/rpcemuspoon/088/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://marutan.net/rpcemuspoon/
COMMENT=	Acorn RiscPC and A7000 emulator
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}/src

GNU_CONFIGURE=	yes

RPCEMUBASE=	${PREFIX}/share/${PKGNAME_NOREV}

INSTALLATION_DIRS=	${RPCEMUBASE}/roms

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fix rom image location.
SUBST_FILES.prefix=	rpc-machdep.c
SUBST_VARS.prefix=	RPCEMUBASE

#post-install:
#	${INSTALL_DATA} ${WRKSRC|/

.include "../../wip/allegro/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
