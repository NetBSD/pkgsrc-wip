# $NetBSD: Makefile,v 1.3 2004/06/15 00:00:47 rillig Exp $

DISTNAME=	pkgclean-20040615
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	peter@pointless.nl
COMMENT=	Quickly clean up all work directories in pkgsrc

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILDLINK=	yes
NO_CONFIGURE=	yes
NO_CHECKSUM=	yes

INSTALLATION_DIRS=	bin man/cat1 man/man1

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkgclean ${PREFIX}/bin/pkgclean
	${INSTALL_MAN} ${WRKSRC}/pkgclean.1 ${PREFIX}/man/man1/pkgclean.1
	${INSTALL_MAN} ${WRKSRC}/pkgclean.cat1 ${PREFIX}/man/cat1/pkgclean.0

SUBST_CLASSES=          path
SUBST_STAGE.path=       post-patch
SUBST_FILES.path=       pkgclean.c pkgclean.1
SUBST_SED.path=         -e "s,@PKGSRCDIR@,${_PKGSRCDIR},g"
SUBST_MESSAGE.path=     "Adjusting pkgsrc directory."

.include "../../mk/bsd.pkg.mk"
