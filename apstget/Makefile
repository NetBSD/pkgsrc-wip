# $NetBSD: Makefile,v 1.34 2012/09/24 16:51:01 asau Exp $

DISTNAME=	apstget-20060410
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pancake@phreaker.net
COMMENT=	apt-get like tool for pkgsrc

DEPENDS+=	pkgfind>=20041020:../../pkgtools/pkgfind
DEPENDS+=	pkg_tarup>=1.6.3:../../pkgtools/pkg_tarup
DEPENDS+=	pkg_chk>=1.54:../../pkgtools/pkg_chk
DEPENDS+=	pkglint>=3.94:../../pkgtools/pkglint

NO_CONFIGURE=	yes
NO_BUILD=	yes

CONF_FILES=	apstget.conf ${PKG_SYSCONFDIR}/apstget.conf

INSTALLATION_DIRS+=	bin libexec

do-extract:
	cp -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/apst-get ${DESTDIR}${PREFIX}/bin/apstget
	${INSTALL_SCRIPT} ${WRKSRC}/apstget-wrapper ${DESTDIR}${PREFIX}/libexec/

.include "../../mk/bsd.prefs.mk"

# AWK compatibilty stuff
.if ${OPSYS} != "Linux"
SUBST_SED.etc= -e "s,-W interactive,,"
.endif

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	post-patch
SUBST_FILES.etc=	apst-get apstget-wrapper
SUBST_SED.etc+=		-e "s,_etc_,${PKG_SYSCONFDIR},g" \
			-e "s,_pfx_,${PREFIX},g" \
			-e "s,_psd_,${PKGSRCDIR},g" \
			-e "s,_dbd_,${PKG_DBDIR},g" \
			-e "s,_makebin_,${MAKE},g"

.include "../../mk/bsd.pkg.mk"
