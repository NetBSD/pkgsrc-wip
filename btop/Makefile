# $NetBSD$

DISTNAME=	btop-1.2.13.20240103
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=aristocratos/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	114a98d813f618ab8ef594eb0de90a2a13dd3a0c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aristocratos/btop
COMMENT=	Colorful TTY resource monitor
LICENSE=	apache-2.0

# This package points to the latest commit in git.
# When moving to pkgsrc-current, this section can be removed.
CONFLICTS=	btop-[0-9]*

DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GCC_REQD+=	10

MAKE_ARGS=	STRIP=true ADDFLAGS="${CXXFLAGS} ${LDFLAGS}" VERBOSE=true

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
