# $NetBSD$

DISTNAME=	TriforceAFL
PKGNAME=	TriforceAFL-0.0
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=nccgroup/}

GITHUB_TAG=	2a8ed329233a921044c903222fc3aa029ef68c69

MAINTAINER=	vishnu@akulpillai.com
HOMEPAGE=	https://github.com/nccgroup/TriforceAFL/
COMMENT=	AFL/QEMU fuzzing with full-system emulation
LICENSE=	apache-2.0

EXTRACT_USING=	gtar
WRKSRC=		${WRKDIR}/TriforceAFL-${GITHUB_TAG}

USE_TOOLS=	bison gmake pkg-config makeinfo perl:build pkg-config

.include "../../lang/python/pyversion.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
