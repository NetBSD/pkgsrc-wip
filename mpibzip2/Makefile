# $NetBSD: Makefile,v 1.2 2012/10/03 15:09:58 asau Exp $
#

DISTNAME=	mpibzip2-0.6
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://compression.ca/mpibzip2/

MAINTAINER=	noud4@home.nl
HOMEPAGE=	http://compression.ca/mpibzip2/
COMMENT=	Parallel implementation of bzip2
LICENSE=	original-bsd

USE_LANGUAGES=	c++

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=	-e 's,/usr,${PREFIX},g'
SUBST_SED.prefix+=	-e 's,@PREFIX@,${PREFIX},'

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PKGNAME:S|-${PKGVERSION}||} ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PKGNAME:S|-${PKGVERSION}||}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1	# TODO this must be wrong

.include "../../parallel/mpi-ch/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
