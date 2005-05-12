# $NetBSD: Makefile,v 1.13 2005/05/12 20:01:42 imilh Exp $
#

DISTNAME=		pkg_select-20050512
CATEGORIES=		pkgtools
MASTER_SITES=	http://imil.net/NetBSD/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://imil.net/
COMMENT=	Curses based pkgsrc system browser / manager

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INCOMPAT_CURSES=		NetBSD-1.5* NetBSD-1.6[-_.]* NetBSD-1.6[A-U]-*
ONLY_FOR_PLATFORM=      NetBSD-*-* FreeBSD-*-* Darwin-*-* DragonFly-*-*

WRKSRC=			${WRKDIR}/pkg_select
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin man/man1

PKG_DBDIR?=	/var/db/pkg

EXAMPLEDIR=	${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EXAMPLEDIR}/${PKGBASE}.conf.example	\
			${PKG_SYSCONFDIR}/${PKGBASE}.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkg_select ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/pkg_select
	${INSTALL_DATA} ${WRKSRC}/${PKGBASE}.conf.example ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/mirrors.cvs ${PREFIX}/share/pkg_select
	${INSTALL_DATA} ${WRKSRC}/mirrors.ftp ${PREFIX}/share/pkg_select
	${INSTALL_MAN} ${WRKSRC}/pkg_select.1 ${PREFIX}/man/man1

SUBST_CLASSES=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	Makefile pkg_select.1
SUBST_SED.path=		-e "s|/usr/pkgsrc|${PKGSRCDIR}|g" \
			-e "s|/usr/pkg|${PREFIX}|g" \
			-e "s|/var/db/pkg|${PKG_DBDIR}|g" \
			-e "s|/usr/bin/make|${MAKE}|g"
SUBST_MESSAGE.path=     "Adjusting path."

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
