# $NetBSD: Makefile,v 1.15 2009/05/26 22:23:54 imilh Exp $
#

DISTNAME=		pkgin-20090527
CATEGORIES=		pkgtools
MASTER_SITES=		http://imil.net/NetBSD/

MAINTAINER=		imil@gcu.info
COMMENT=		Apt / yum like tool for managing pkgsrc binary packages

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

WRKSRC=			${WRKDIR}/pkgin

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Adjusting path.
SUBST_FILES.path=	Makefile actions.c
SUBST_SED.path=		-e "s|/usr/pkg|${PREFIX}|g"
SUBST_SED.path+=	-e "s|/usr/sbin|${PKG_TOOLS_BIN}|g"

USE_FEATURES=			nbcompat
NBCOMPAT_CONFIGURE_ARGS=	--enable-db

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkgin ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pkgin.1	\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

# libfetch has no builtin.mk and is included in NetBSD>=5
.if ${OPSYS} != "NetBSD" || \
	(${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[0-4].*))
.	include "../../net/libfetch/buildlink3.mk"
.endif

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
