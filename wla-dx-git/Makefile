# $NetBSD$
PKGNAME=		wla-dx-9.6
CATEGORIES=		devel

GIT_REPOSITORIES=		wla-dx
GIT_REPO.wla-dx=		git://github.com/vhelin/wla-dx

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.villehelin.com/wla.html
COMMENT=	Assembler that targets many CPUs
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/wla-dx

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=		bin
INSTALLATION_DIRS+=		share/doc/${PKGBASE}

WLADX_BINARIES=		wla-6502 wla-6510 wla-65816 wla-65c02 wla-gb wla-huc6280 \
					wla-spc700 wla-z80 wlab wlalink

do-install:
.for f in ${WLADX_BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/${f} ${DESTDIR}${PREFIX}/bin
.endfor
.for f in README.md FILE_FORMATS CHANGELOG
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
.endfor

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
