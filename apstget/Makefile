# $NetBSD: Makefile,v 1.8 2004/11/03 19:23:08 poppnk Exp $

DISTNAME=	apstget-20041103
CATEGORIES=	pkgtools wip
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pancake@phreaker.net
COMMENT=	apt-get like tool for pkgsrc

DEPENDS+=	pkgfind>=20041020:../../pkgtools/pkgfind
DEPENDS+=	pkg_tarup>=1.6.3:../../pkgtools/pkg_tarup
DEPENDS+=	pkg_chk>=1.51:../../pkgtools/pkg_chk
DEPENDS+=	pkglint>=3.94:../../pkgtools/pkglint

NO_BUILDLINK=	yes
NO_CONFIGURE=	yes
NO_CHECKSUM=	yes
NO_BUILD=	yes

CONF_FILES=	${PKG_SYSCONFDIR}/apstget.conf

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/apst-get ${PREFIX}/bin/apst-get
	${INSTALL_SCRIPT} ${WRKSRC}/apstget-wrapper ${PREFIX}/libexec/

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
SUBST_SED.etc= -e "s,-W interactive,,"
.endif

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	post-patch
SUBST_FILES.etc=	apst-get apstget-wrapper
SUBST_SED.etc+=		-e "s,_etc_,${PKG_SYSCONFDIR},g" \
			-e "s,_pfx_,${PREFIX},g" \
			-e "s,_psd_,${PKGSRCDIR},g" \
			-e "s,_makebin_,${MAKE},g"

.include "../../mk/bsd.pkg.mk"
