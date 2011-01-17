# $NetBSD: Makefile,v 1.1.1.1 2011/01/17 22:07:32 jihbed Exp $
#

VERSION=	3.5
DISTNAME=	cweb-x3.5
PKGNAME=	cwebx-${VERSION}
CATEGORIES=	print
MASTER_SITES=	http://www-math.univ-poitiers.fr/~maavl/CWEBx/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www-math.univ-poitiers.fr/~maavl/CWEBx/
COMMENT=	CWEBx system is a system for Structured Software Documentation

DEPENDS+=	web2c-[0-9]*:../../print/web2c

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/cwebx

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/doc/cwebx ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ctanglex ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cweavex ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man1/cweb.1 	\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/cwebx.1
	${INSTALL_DATA} ${WRKSRC}/manual.dvi ${DESTDIR}${PREFIX}/share/doc/cwebx

.include "../../mk/bsd.pkg.mk"
