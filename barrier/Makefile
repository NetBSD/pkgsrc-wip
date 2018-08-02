# $NetBSD$

GITHUB_PROJECT=	barrier
DISTNAME=	v2.1.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=debauchee/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	maya@NetBSD.org
HOMEPAGE=	https://github.com/debauchee/barrier/
COMMENT=	Let a user share a mouse and keyboard among computers
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/barrier-2.1.1
USE_LANGUAGES=		c c++11
# Main configuration is CMake, but subdirectories are GNU configure.
# We need to set GNU_CONFIGURE=yes for config.{guess,sub} overrides to kick in.
# We override the do-configure target to prevent pkgsrc from running both
# configuration mechanisms.
USE_CMAKE=	yes
USE_CMAKE=		yes
GNU_CONFIGURE=		yes

CONFIG_SUB_OVERRIDE+=	ext/gmock/build-aux/config.sub
CONFIG_SUB_OVERRIDE+=	ext/gtest/build-aux/config.sub
CONFIG_GUESS_OVERRIDE+=	ext/gmock/build-aux/config.guess
CONFIG_GUESS_OVERRIDE+=	ext/gtest/build-aux/config.guess

USE_X11=		yes

.PHONY: do-configure
do-configure: do-configure-cmake


INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/${PKGBASE}

EXAMPLES=	MacReadme.txt org.barrier-foss.org.barrierc.plist \
		org.barrier-foss.org.barriers.plist barrier.conf.example \
		barrier.conf.example-advanced barrier.conf.example-basic

do-install:
.for p in barrierc barriers
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${p} ${DESTDIR}${PREFIX}/bin/${p}
	${INSTALL_MAN} ${WRKSRC}/doc/${p}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${p}.1
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/bin/barrier ${DESTDIR}${PREFIX}/bin/barrier
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}
.endfor

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
