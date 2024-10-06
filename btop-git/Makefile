# $NetBSD$

DISTNAME=	btop-1.4.0.20240924
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=aristocratos/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	2e7208d59c54515080027a5ecbb89d2054047985

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aristocratos/btop
COMMENT=	Colorful TTY resource monitor
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

USE_CXX_FEATURES+=	c++20

INSTALLATION_DIRS=	${PKGMANDIR}/man1

CXXFLAGS+=	-DNDEBUG
MAKE_ENV+=	STRIP=true VERBOSE=true

post-extract:
	${CHMOD} -R g-w ${WRKSRC}

post-build:
	${CP} ${FILESDIR}/btop.1 ${WRKDIR}/btop.1

post-install:
	${INSTALL_MAN} ${WRKDIR}/btop.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
