# $NetBSD$

DISTNAME=	${GHCOMMIT}
PKGNAME=	sailor-${VERSION}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=NetBSDfr/sailor/archive/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=NetBSDfr/sailor/}
COMMENT=	Wannabe portable container system
LICENSE=	modified-bsd

VERSION=	0.2.20160211
GHCOMMIT=	e86d0440a4bcc1b6a49602e084079778d3418861
DEPENDS=	pkgin>=0.9.3:../../pkgtools/pkgin
DEPENDS=	rsync-[0-9]*:../../net/rsync
DEPENDS=	pkg_tarup-[0-9]*:../../pkgtools/pkg_tarup

NO_BUILD=		yes
USE_LANGUAGES=		# none
USE_TOOLS+=		sh:run sed:run sed:build awk:run curl:run
EGDIR=			${PREFIX}/share/examples/sailor
CONF_FILES=		${EGDIR}/empty.conf \
			${PKG_SYSCONFDIR}/${PKGBASE}/empty.conf
DOCDIR=			share/doc/sailor
OWN_DIRS+=		${PKG_SYSCONFDIR}/${PKGBASE}
INSTALLATION_DIRS+=	sbin ${EGDIR} share/sailor/include share/sailor/ships ${DOCDIR}
AUTO_MKDIRS=		yes
WRKSRC=			${WRKDIR}/sailor-${GHCOMMIT}

SUBST_CLASSES+=		include
SUBST_STAGE.include=	pre-configure
SUBST_MESSAGE.include=	Substituting path includes.
SUBST_FILES.include=	sailor.sh
SUBST_SED.include=	-e "s|include=include|include=${PREFIX}/share/sailor/include|g"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sailor.sh ${DESTDIR}${PREFIX}/sbin/sailor
	${INSTALL_DATA} ${WRKSRC}/include/*.sh ${DESTDIR}${PREFIX}/share/sailor/include/
	${INSTALL_DATA} ${WRKSRC}/examples/*.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/${DOCDIR}
	cd ${WRKSRC} && ${FIND} ./ships/ -type d -exec ${INSTALL_DATA_DIR} \
		${DESTDIR}${PREFIX}/share/sailor/{} \;
	cd ${WRKSRC} && ${FIND} ./ships/ \! -type d -exec ${INSTALL_DATA} {} \
		${DESTDIR}${PREFIX}/share/sailor/{} \;

.include "../../mk/bsd.pkg.mk"
