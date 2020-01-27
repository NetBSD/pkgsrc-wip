# $NetBSD: Makefile,v 1.4 2014/11/03 22:01:04 ryo-on Exp $
#

RPCEMUVER=	0.8.12
DISTNAME=	rpcemu-${RPCEMUVER}
CATEGORIES=	emulators
MASTER_SITES=	-http://marutan.net/rpcemu/cgi/download.php?sFName=${RPCEMUVER}/rpcemu-${RPCEMUVER}.tar.gz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://marutan.net/rpcemu/
COMMENT=	Acorn RiscPC and A7000 emulator
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}/src

GNU_CONFIGURE=	yes

#RPCEMUBASE=	${PREFIX}/share/${PKGNAME_NOREV}
RPCEMUBASE=	./

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fix rom image location.
SUBST_FILES.prefix=	rpc-machdep.c
SUBST_VARS.prefix=	RPCEMUBASE

.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
