# $NetBSD: Makefile,v 1.2 2004/06/14 18:36:24 xtraeme Exp $

DISTNAME=	pkgfind-20040614
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	peter@pointless.nl
COMMENT=	Find packages by package name in pkgsrc

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILDLINK=	yes
NO_CONFIGURE=	yes
NO_CHECKSUM=	yes

INSTALLATION_DIRS=	bin man/cat1 man/man1

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkgfind ${PREFIX}/bin/pkgfind
	${INSTALL_MAN} ${WRKSRC}/pkgfind.1 ${PREFIX}/man/man1/pkgfind.1
	${INSTALL_MAN} ${WRKSRC}/pkgfind.cat1 ${PREFIX}/man/cat1/pkgfind.0

SUBST_CLASSES=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	${FILESDIR}/pkgfind.c ${FILESDIR}/pkgfind.1
SUBST_SED.path=		-e "s,/usr/pkgsrc,${_PKGSRCDIR},g"
SUBST_MESSAGE.path=	"Adjusting pkgsrc directory."

.include "../../mk/bsd.pkg.mk"
