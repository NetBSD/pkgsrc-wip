# $NetBSD$

DISTNAME=	honk-1.2.1
MASTER_SITES=	${HOMEPAGE}/d/
EXTRACT_SUFX=	.tgz
CATEGORIES=	www

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://humungus.tedunangst.com/r/honk
COMMENT=	ActivityPub server with minimal setup and support costs
LICENSE=	isc
USE_TOOLS+=	pax

DEPENDS+=	sqlite3-[0-9]*:../../databases/sqlite3

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

RCD_SCRIPTS=	honk
FILES_SUBST+=	HONK_DATA=${HONK_DATA}
FILES_SUBST+=	EGDIR=${EGDIR}

SUBST_CLASSES+=		readme
SUBST_MESSAGE.readme=	replacing paths in pkgsrc README file
SUBST_STAGE.readme=	pre-configure
SUBST_FILES.readme=	README.pkgsrc
SUBST_VARS.readme=	PREFIX
SUBST_VARS.readme+=	HONK_DATA

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	VARBASE
HONK_USER?=	honk
HONK_GROUP?=	honk
HONK_DATA?=	${VARBASE}/chroot/honk

PKG_GROUPS+=	${HONK_GROUP}
PKG_USERS+=	${HONK_USER}:${HONK_GROUP}

# since we include go-module.mk after bsd.pref.mk:
.for bin in autobonker gettoken saytheday sprayandpray youvegothonks
CHECK_PIE_SKIP+=	bin/${bin}
CHECK_RELRO_SKIP+=	bin/${bin}
.endfor

post-extract:
	${CP} ${FILESDIR}/README.pkgsrc ${WRKSRC}/README.pkgsrc

# figure out why regular go build does not work here.
do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} make all
	cd ${WRKSRC}/toys && ${SETENV} ${MAKE_ENV} make all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/honk ${DESTDIR}${PREFIX}/bin/
.for bin in autobonker saytheday sprayandpray youvegothonks gettoken
	${INSTALL_PROGRAM} ${WRKSRC}/toys/${bin} ${DESTDIR}${PREFIX}/bin
.endfor
.for page in 1 3 5 7 8
	${MKDIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man${page}
.endfor
	${MKDIR} ${DESTDIR}/${EGDIR}
	${MKDIR} ${DESTDIR}/${DOCDIR}
	${MKDIR} ${DESTDIR}/${DOCDIR}/toys
.for page in 1 3 5 8
	${INSTALL_MAN} ${WRKSRC}/docs/honk.${page} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man${page}
.endfor
	# activitypub.7, hfcs.1, intro.1, vim.3 are potential collision candidates.
	${INSTALL_MAN} ${WRKSRC}/docs/activitypub.7 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/honk_activitypub.7
	${INSTALL_MAN} ${WRKSRC}/docs/hfcs.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/honk_hfcs.1
	${INSTALL_MAN} ${WRKSRC}/docs/intro.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/honk_intro.1
	${INSTALL_MAN} ${WRKSRC}/docs/vim.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/honk_vim.3
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}/README
	${INSTALL_DATA} ${WRKSRC}/toys/README ${DESTDIR}${DOCDIR}/toys/README
	cd ${WRKSRC} && ${PAX} -rw views ${DESTDIR}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/schema.sql ${DESTDIR}/${EGDIR}/schema.sql
	${INSTALL_DATA} ${WRKSRC}/README.pkgsrc ${DESTDIR}${DOCDIR}/README.pkgsrc

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
