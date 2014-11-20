# $NetBSD: Makefile,v 1.1 2014/11/20 05:36:32 makoto Exp $
#

DISTNAME=	download
PKGNAME=	fastjar-0.94
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fastjar/}
MASTER_SITES+=	http://sourceforge.net/projects/fastjar/files/fastjar/0.94/fastjar-0.94.tar.gz/
EXTRACT_SUFX=

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fastjar.sourceforge.net/
COMMENT=	C language version of the 'jar' archiver normally used by Java
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	fastjar-0.94
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS=	tar
GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	${PKGMANDIR}/man1

pre-patch:
	(cd ${WRKDIR};  \
	 mv download ${PKGNAME_NOREV}.tar.gz ; \
	 tar zxf ${PKGNAME_NOREV}.tar.gz )
post-install:
	${INSTALL_MAN} ${WRKSRC}/fastjar.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/grepjar.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
