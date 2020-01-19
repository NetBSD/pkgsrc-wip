# $NetBSD$

DISTNAME=	texlive.tlpdb
PKGNAME=	texlive-tlpdb-2019.11.04
CATEGORIES=	print
MASTER_SITES=	http://mirrors.ctan.org/systems/texlive/tlnet/tlpkg/
EXTRACT_SUFX=	.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mirrors.ctan.org/systems/texlive/tlnet/tlpkg/
COMMENT=	TeX Live (plain text) database
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
USE_TOOLS+=	xzcat

INSTALLATION_DIRS=	share/tlpkg

do-build::
	${XZCAT} ${WRKDIR}/${DISTFILES} > ${WRKDIR}/texlive.tlpdb

do-install:
	${INSTALL_DATA} ${WRKDIR}/texlive.tlpdb \
		${DESTDIR}${PREFIX}/share/tlpkg/

.include "../../mk/bsd.pkg.mk"
