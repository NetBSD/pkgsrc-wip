# $NetBSD: Makefile,v 1.4 2004/10/25 17:14:19 poppnk Exp $

DISTNAME=	apstget-20041025
CATEGORIES=	pkgtools wip
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pancake@phreaker.net
COMMENT=	apt-get like tool for pkgsrc

DEPENDS+=	pkgfind>=20041020:../../pkgtools/pkgfind
DEPENDS+=	pkg_tarup>=1.6.3:../../pkgtools/pkg_tarup
DEPENDS+=	pkg_chk>=1.51:../../pkgtools/pkg_chk

NO_BUILDLINK=	yes
NO_CONFIGURE=	yes
NO_CHECKSUM=	yes
NO_BUILD=	yes

CONF_FILES=	${PKG_SYSCONFDIR}/apstget.conf

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/apst-get ${PREFIX}/bin/apst-get

SUBST_CLASSES=		etc
SUBST_STAGE.etc=	post-patch
SUBST_FILES.etc=	apst-get
SUBST_SED.etc=		-e "s,_etc_,${PKG_SYSCONFDIR},g" \
			-e "s,_pfx_,${PREFIX},g" \
			-e "s,_psd_,${PKGSRCDIR},g"

.include "../../mk/bsd.pkg.mk"
