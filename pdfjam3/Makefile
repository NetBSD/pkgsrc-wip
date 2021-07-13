# $NetBSD$
#

GITHUB_PROJECT=	pdfjam
GITHUB_TAG=	v3.03
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}3-${DISTNAME:S/v//}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=rrthomas/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	https://github.com/rrthomas/pdfjam
COMMENT=	Small collection of PDF utilities
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-eso-pic-[0-9]*:../../print/tex-eso-pic
DEPENDS+=	tex-pdfpages-[0-9]*:../../print/tex-pdfpages

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/pdfjam ${DESTDIR}${PREFIX}/bin/pdfjam3
	${INSTALL_MAN} ${WRKSRC}/man1/pdfjam.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pdfjam3.1

.include "../../mk/bsd.pkg.mk"
