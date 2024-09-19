# $NetBSD$

DISTNAME=	pear_${PORTVERSION}_src_all
PKGNAME=	pear-merger-${PORTVERSION}
CATEGORIES=	biology
MASTER_SITES=	https://depot.galaxyproject.org/software/pear/

MAINTAINER=	weinertw@uwm.edu
HOMEPAGE=	http://sco.h-its.org/exelixis/web/software/pear/
COMMENT=	Memory-efficient and highly accurate pair-end read merger
LICENSE=	cc-by-sa-v3.0

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/pear-${PORTVERSION}-src

PORTVERSION=	0.9.6

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pear ${DESTDIR}${PREFIX}/bin/pearRM
	${INSTALL_MAN} ${WRKSRC}/man/pear.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pearRM.1

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
