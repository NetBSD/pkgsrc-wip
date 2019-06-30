# $NetBSD$

DISTNAME=	wla-dx-9.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=vhelin/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.villehelin.com/wla.html
COMMENT=	Assembler that targets many CPUs
LICENSE=	gnu-gpl-v2

.include "options.mk"

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=		bin
INSTALLATION_DIRS+=		${PKGMANDIR}/man1
INSTALLATION_DIRS+=		${PKGMANDIR}/man7
INSTALLATION_DIRS+=		share/doc/${PKGBASE}

WLADX_BINARIES=		wla-6502 wla-6510 wla-65816 wla-65c02 wla-gb wla-huc6280 \
					wla-spc700 wla-z80 wlab wlalink

do-install:
.for f in ${WLADX_BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/${f} ${DESTDIR}${PREFIX}/bin
.endfor
.if !empty(PKG_OPTIONS:Mdoc)
.  for f in binaries/doc/wla-dx.txt binaries/doc/wla-dx.html FILE_FORMATS CHANGELOG
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
.  endfor
.  for f in binaries/doc/*.1
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.  endfor
.  for f in binaries/doc/*.7
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7
.  endfor
.endif

.include "../../mk/bsd.pkg.mk"
