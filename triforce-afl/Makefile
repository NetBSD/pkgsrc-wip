# $NetBSD$

DISTNAME=	${GIT_COMMIT}
PKGNAME=	TriforceAFL-0.0
CATEGORIES=	emulators
MASTER_SITES=	https://github.com/nccgroup/TriforceAFL/archive/

GIT_COMMIT=	73ec279d5ee3aa84fd7e4e8c3818428d437d8fa7

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	https://github.com/nccgroup/
COMMENT=	AFL/QEMU fuzzing with full-system emulation
#LICENSE=	# TODO: (see mk/license.mk)

EXTRACT_USING=	gtar
WRKSRC=		${WRKDIR}/TriforceAFL-${GIT_COMMIT}

USE_TOOLS=	gmake pkg-config makeinfo perl:build

# url2pkg-marker (please do not remove this line.)
.include "../../lang/python/pyversion.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
