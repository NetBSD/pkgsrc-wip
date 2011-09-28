# $NetBSD: Makefile,v 1.1.1.1 2011/09/28 14:57:12 ryo-on Exp $
#

DISTNAME=	rpcemu-20110928
CATEGORIES=	emulators
MASTER_SITES=	http://ryo-on.users.sourceforge.net/distrib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://marutan.net/rpcemuspoon/
COMMENT=	Acorn RiscPC and A7000 emulator
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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
