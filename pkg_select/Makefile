# $NetBSD: Makefile,v 1.4 2005/02/22 09:52:25 imilh Exp $
#

DISTNAME=		pkg_select-20050222
CATEGORIES=		pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	imil@gcu.info
COMMENT=	Curses based pkg system browser / manager

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ONLY_FOR_PLATFORM=      NetBSD-*-* FreeBSD-*-*

USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes
NO_CHECKSUM=	yes

INSTALLATION_DIRS=	bin man/man1

PKG_DBDIR?=	/var/db/pkg

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkg_select ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pkg_select.1 ${PREFIX}/man/man1

SUBST_CLASSES=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	Makefile pkg_select.1
SUBST_SED.path=         -e "s|/usr/pkgsrc|${PKGSRCDIR}|g" \
			-e "s|/var/db/pkg|${PKG_DBDIR}|g" \
			-e "s|/usr/bin/make|${MAKE}|g"
SUBST_MESSAGE.path=     "Adjusting path."

.include "../../mk/bsd.pkg.mk"
