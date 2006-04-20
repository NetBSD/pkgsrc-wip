# $NetBSD: Makefile,v 1.23 2006/04/20 13:36:43 cheusov Exp $
#

DISTNAME=	pkg_select-20051209
CATEGORIES=	pkgtools
MASTER_SITES=	http://imil.net/NetBSD/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://imil.net/wp/pkg_select/
COMMENT=	Curses-based pkgsrc system browser / manager

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INCOMPAT_CURSES=	NetBSD-1.*-*
ONLY_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-* Darwin-*-* DragonFly-*-*

WRKSRC=			${WRKDIR}/pkg_select
NO_CONFIGURE=		yes

INSTALLATION_DIRS=	bin man/man1

.include "../../mk/bsd.prefs.mk"

PKG_DBDIR?=		/var/db/pkg

EXAMPLEDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EXAMPLEDIR:Q}/${PKGBASE:Q}.conf.example	\
				${PKG_SYSCONFDIR:Q}/${PKGBASE:Q}.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/pkg_select ${PREFIX:Q}/bin
	${INSTALL_DATA_DIR} ${EXAMPLEDIR:Q}
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/pkg_select
	${INSTALL_DATA} ${WRKSRC:Q}/${PKGBASE:Q}.conf.example ${EXAMPLEDIR:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/mirrors.cvs ${PREFIX:Q}/share/pkg_select
	${INSTALL_DATA} ${WRKSRC:Q}/mirrors.ftp ${PREFIX:Q}/share/pkg_select
	${INSTALL_MAN} ${WRKSRC:Q}/pkg_select.1 ${PREFIX:Q}/${PKGMANDIR}/man1

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	Makefile pkg_select.1
SUBST_SED.path=		-e 's|/usr/pkgsrc|${PKGSRCDIR}|g'		\
			-e 's|/usr/pkg|${PREFIX}|g'			\
			-e 's|/var/db/pkg|${PKG_DBDIR}|g'		\
			-e 's|/usr/bin/make|${MAKE}|g'
SUBST_MESSAGE.path=	Adjusting path.

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
